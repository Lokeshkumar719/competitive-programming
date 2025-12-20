class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxi=0;
        int mini=0;
        for(int i=0;i<k;i++){
            mini+=nums[i];
        }
        for(int i=n-k;i<n;i++){
            maxi+=nums[i];
        }
        return abs(maxi-mini);
    }
};