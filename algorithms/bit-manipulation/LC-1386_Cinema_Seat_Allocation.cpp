class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();
        unordered_map<int,int> mp;
        for(auto &it : reservedSeats){
            int row = it[0];
            int seat = it[1];
            mp[row] |= (1 << seat);
        }

        int groupAMask = ((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5));
        int groupBMask = ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7));
        int groupCMask = ((1 << 6) | (1 << 7) | (1 << 8) | (1 << 9));

        int ans = (n - (int)mp.size())*2;
        for(auto &[row, bookedSeatMask]: mp){
            bool groupA = bookedSeatMask & groupAMask;
            bool groupB = bookedSeatMask & groupBMask;
            bool groupC = bookedSeatMask & groupCMask;

            if(!groupA && !groupC){
                ans += 2;
            }else if(!groupA || !groupB || !groupC){
                ans += 1;
            }

        }

        return ans;
    }
};