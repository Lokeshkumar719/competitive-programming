class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n=nums.size();
        long long suffMin=(long long)nums[n-1];
        long long ans=LLONG_MIN;
        long long sum=(long long)accumulate(nums.begin(),nums.end(),0LL);
        long long suffSum=nums[n-1];
        for(int i=n-2;i>=0;i--){
          long long preSum=sum-suffSum;
          suffSum+=(long long)nums[i];
          ans=max( ans,(long long)(preSum-suffMin) );
          suffMin=min(suffMin,(long long)nums[i]);
        }
        return ans;
    }
};