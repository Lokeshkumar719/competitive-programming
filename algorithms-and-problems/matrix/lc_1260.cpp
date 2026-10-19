class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int tot_elements = m * n;
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int flat_idx = (i * n + j);
                int newIdx = (flat_idx + k) % tot_elements;
                int newRow = newIdx / n;
                int newCol = newIdx % n;
                ans[newRow][newCol] = grid[i][j];
            }
        }
        return ans;
    }
};