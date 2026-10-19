class Solution {
public:
    typedef pair<int,pair<int,int>> pip;
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        priority_queue<pip,vector<pip>,greater<pip>>pq;
        int dirc[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        pq.push({grid[0][0],{0,0}});
        dist[0][0]=grid[0][0];
        while(!pq.empty()){
            int dis=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dirc[i][0];
                int ncol=col+dirc[i][1];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n){
                    int wt=(grid[nrow][ncol]>dist[row][col])? grid[nrow][ncol]-dist[row][col] : 0;
                    if(dist[nrow][ncol]>dist[row][col]+wt){
                        dist[nrow][ncol]=dist[row][col]+wt;
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};