class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<int>dp(n+1);
        // dp[i] = maximum price that can be obtained from rod of length i
        dp[0]=0;dp[1]=price[0];
        for(int len=2;len<=n;len++){
            for(int cut=1;cut<=len;cut++){
                dp[len]=max(dp[len],price[cut-1]+dp[len-cut]);
            }
        }
        return dp[n];
    }
};