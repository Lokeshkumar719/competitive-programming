class Solution {
using state=pair<int,pair<int,int>>;
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        const int INF=1e9;
        int dirc[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        vector<vector<vector<int>>>dist(n,vector<vector<int>>(m,vector<int>(k+1,INF)));
        queue<state>q;
        q.push({0,{0,0}});
        dist[0][0][0]=0;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second.first;
            int obs=q.front().second.second;
            if(i==n-1 && j==m-1) return dist[i][j][obs];
            q.pop();
            for(int d=0;d<4;d++){
                int ni=i+dirc[d][0];
                int nj=j+dirc[d][1];
                if(ni>=0 && ni<n && nj>=0 && nj<m){
                    int newObs=obs+grid[ni][nj];
                    if(newObs>k) continue;
                    if(dist[ni][nj][newObs]==INF){
                        q.push({ni,{nj,newObs}});
                        dist[ni][nj][newObs]=dist[i][j][obs]+1;
                    }
                }
            }
        }
       return -1;
    }
};