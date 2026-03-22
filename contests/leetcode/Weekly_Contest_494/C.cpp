class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n=nums.size();    
        vector<vector<int>>dp(n+1,vector<int>((1<<15+1),1e9));
        dp[n][0]=0;
        int maxi=1<<14;
        for(int i=n-1;i>=0;i--){
            for(int k=0;k<=maxi;k++){
                dp[i][k]=min(dp[i+1][nums[i]^k],1+dp[i+1][k]);
            }
        }
        return (dp[0][target]!=1e9)? dp[0][target]:-1;
    }
};