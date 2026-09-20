class Solution {
public:
    vector<vector<int>> dp;
    int minDays(int n) { 
        dp.resize(n+1,vector<int>(452,0));
        for(int i=1;i<=n;i++){
            dp[i][1] = 1 + dp[i-1][2];
            for(int j=450;j>=2;j--){
                int ans = 1 + dp[i][1];
                if(j<=i){
                    ans = min(ans,1+dp[i-j][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[n][1];
    }
};