class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(1024, 0)));

        dp[0][0][grid[0][0]] = 1;
        int xr = grid[0][0];
        for (int i = 1; i < m; i++) {
            xr ^= grid[i][0];
            dp[i][0][xr] = 1;
        }

        xr = grid[0][0];
        for (int j = 1; j < n; j++) {
            xr ^= grid[0][j];
            dp[0][j][xr] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int xr = 0; xr < 1024; xr++) {
                    if (dp[i - 1][j][xr] || dp[i][j - 1][xr])
                        dp[i][j][xr^grid[i][j]] = 1;
                }
            }
        }

        for (int i = 0; i <= 1023; i++) {
            if (dp[m - 1][n - 1][i])
                return i;
        }

        return -1;
    }
};