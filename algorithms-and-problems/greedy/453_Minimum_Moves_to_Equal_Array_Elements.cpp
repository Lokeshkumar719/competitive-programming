class Solution {
public:
    using ll = long long;
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        ll sum = 0;
        int mini = INT_MAX;
        for(auto &ele:nums){
            sum += ele;
            mini = min(mini,ele);
        }
        return sum - n*mini;
    }
};