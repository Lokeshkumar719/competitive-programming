class Solution {
public:
    bool bfs(vector<vector<int>>& grid,vector<vector<int>> &vis,int i,int j,int k){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]  = true;
        int dirc[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
        int sum = grid[i][j] % k;
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for(int d = 0;d<4;d++){
                int ni = i + dirc[d][0];
                int nj = j + dirc[d][1];
                if(ni < 0 || ni>=grid.size() || nj<0 || nj>=grid[0].size() || vis[ni][nj] || !grid[ni][nj])
                    continue;
                sum = (sum + grid[ni][nj]) % k;
                q.push({ni,nj});
                vis[ni][nj] = true;
            }
        }

        return !sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,false));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] && bfs(grid,vis,i,j,k))
                    ans++;
            }
        }
        return ans;
    }
};