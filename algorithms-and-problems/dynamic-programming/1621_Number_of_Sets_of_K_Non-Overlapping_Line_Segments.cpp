class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;
    
    int sub(ll a, ll b) {
        return (a - b + MOD) % MOD;
    }
    
    int add(ll a, ll b) {
        return (a + b) % MOD;
    }
        
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            dp[0][i] = 1;

        for (int num_sticks = 1; num_sticks <= k; num_sticks++) {
            vector<int> pref = dp[num_sticks - 1];

            for (int j = 1; j < n; j++)
                pref[j] = (pref[j] + pref[j - 1]) % MOD;

            for (int i = n - 2; i >= 0; i--) {

                ll take = sub((ll)pref[n-1],(ll)pref[i]);

                ll notTake = dp[num_sticks][i + 1] % MOD;

                dp[num_sticks][i] = add(take,notTake);
            }
        }

        return dp[k][0];
    }
};