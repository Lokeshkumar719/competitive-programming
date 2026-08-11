class Solution {
public:
    const int MOD = 1e9 + 7;
    int gcd(int a, int b) {
        if (a == -1)
            return b;
        return !b ? a : gcd(b, a % b); 
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(begin(nums), end(nums));
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(maxi + 2, vector<int>(maxi + 2)));
        for (int g1 = 0; g1 <= maxi; g1++) {
            dp[n][g1] = 1;
        }
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int g1 = -1; g1 <= maxi; g1++) {
                for (int g2 = -1; g2 <= maxi; g2++) {
                    int ans = 0;
                    ans = (ans + dp[idx + 1][gcd(g1, nums[idx]) + 1][g2 + 1]) %
                          MOD;
                    ans = (ans + dp[idx + 1][g1 + 1][gcd(g2, nums[idx]) + 1]) %
                          MOD;
                    ans = (ans + dp[idx + 1][g1 + 1][g2 + 1]) % MOD;

                    dp[idx][g1 + 1][g2 + 1] = ans;
                }
            }
        }
        return dp[0][0][0];
    }
};