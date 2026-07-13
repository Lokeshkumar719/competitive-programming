class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        vector<string> ans(m, string(n, '#'));
        if (k == 1) {
            for (int j = 0; j < n; j++)
                ans[0][j] = '.';
            for (int i = 0; i < m; i++)
                ans[i][n - 1] = '.';
            return ans;
        }
        if (m == 1 || n == 1)
            return {};
        if (k == 2) {
            ans[0][0] = ans[0][1] = ans[1][0] = ans[1][1] = '.';
            for (int j = 1; j < n; j++)
                ans[1][j] = '.';
            for (int i = 1; i < m; i++)
                ans[i][n - 1] = '.';
            return ans;
        }
        if (k == 3) {
            if (n >= 3) {
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 3; j++) {
                        ans[i][j] = '.';
                    }
                }

                for (int j = 2; j < n; j++)
                    ans[1][j] = '.';
                for (int i = 1; i < m; i++)
                    ans[i][n - 1] = '.';
                return ans;
            }
            if (m >= 3) {
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 2; j++) {
                        ans[i][j] = '.';
                    }
                }

                for (int j = 1; j < n; j++)
                    ans[2][j] = '.';
                for (int i = 2; i < m; i++)
                    ans[i][n - 1] = '.';
                return ans;
            }

            return {};
        }
        if (n >= 4) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 4; j++) {
                    ans[i][j] = '.';
                }
            }

            for (int j = 3; j < n; j++)
                ans[1][j] = '.';
            for (int i = 1; i < m; i++)
                ans[i][n - 1] = '.';
            return ans;
        }
        if (m >= 4) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 2; j++) {
                    ans[i][j] = '.';
                }
            }

            for (int j = 1; j < n; j++)
                ans[3][j] = '.';
            for (int i = 3; i < m; i++)
                ans[i][n - 1] = '.';
            return ans;
        }

        if (m >= 3 && n >= 3) {
            ans[0][0] = ans[0][1] = '.';
            ans[1][0] = ans[1][1] = ans[1][2] = '.';
            ans[2][1] = ans[2][2] = '.';
            for (int j = 2; j < n; j++)
                ans[2][j] = '.';
            for (int i = 2; i < m; i++)
                ans[i][n - 1] = '.';
            return ans;
        }

        return {};
    }
};