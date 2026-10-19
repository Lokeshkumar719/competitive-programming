class Solution {
public:
    // dp state : number of subseqence of s[0 ... i-1](s of length i) equals to t[0 ... j-1](t of length j)
    // so base cases dp[0][anything>0] = 0
    // and dp[anything>=0][0] = 0 // for 0 also 
    using ull = unsigned long long;
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<ull>> dp(m+1,vector<ull>(n+1,0));
        for(int i=0;i<=m;i++)
            dp[i][0] = 1; // dp[0][0] will also be 1 and not 0

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[m][n];
    }
};