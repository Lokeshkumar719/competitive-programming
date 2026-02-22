class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int cnt2=0;
        bool isTurn=true;
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                isTurn=(!(isTurn));
            }
            if((i%6)==5){
                isTurn=(!(isTurn));
            }
            if(isTurn){
                cnt+=nums[i];
            }else cnt-=nums[i];
        }
        return cnt;
    }
};