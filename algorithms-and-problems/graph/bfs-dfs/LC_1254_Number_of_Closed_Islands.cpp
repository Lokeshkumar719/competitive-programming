class Solution {
public:
    bool bfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j,
             int m, int n) {
        bool flag = !(i == 0 || j == 0 || i == m - 1 || j == n - 1);
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;
        int dirc[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int ni = i + dirc[d][0];
                int nj = j + dirc[d][1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n || vis[ni][nj] ||
                    grid[ni][nj])
                    continue;
                if (ni == 0 || nj == 0 || ni == m - 1 || nj == n - 1)
                    flag = false;

                q.push({ni, nj});
                vis[ni][nj] = true;
            }
        }

        return flag;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j] && !vis[i][j] && bfs(grid, vis, i, j, m, n))
                    ans++;
            }
        }
        return ans;
    }
};