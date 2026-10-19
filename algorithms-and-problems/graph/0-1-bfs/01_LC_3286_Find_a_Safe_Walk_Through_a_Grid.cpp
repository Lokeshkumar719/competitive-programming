class Solution {
using pii = pair<int,int>;
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        deque<pii> dq;
        vector<vector<int>>cost(m,vector<int>(n,1e9));
        cost[0][0]=grid[0][0];
        dq.push_back({0,0});

        int dirc[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
        while(!dq.empty()){
            auto [i,j] = dq.front();
            dq.pop_front();
            for(int d=0;d<4;d++){
                int ni = i+dirc[d][0];
                int nj = j+dirc[d][1];
                if(ni>=0 && ni<m && nj>=0 && nj<n){
                    int newCost=cost[i][j]+grid[ni][nj];
                    if(newCost<cost[ni][nj]){
                        cost[ni][nj]=newCost;
                        (grid[ni][nj])? dq.push_back({ni,nj}):dq.push_front({ni,nj}); 
                    }
                }
            }
        }
        return cost[m-1][n-1]<health;
    }
};