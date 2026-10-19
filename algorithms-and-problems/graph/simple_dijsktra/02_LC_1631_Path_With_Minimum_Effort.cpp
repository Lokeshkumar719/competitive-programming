class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            int diff=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            // neighbours
            int dirc[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
            for(int d=0;d<4;d++){
                int ni=i+dirc[d][0];
                int nj=j+dirc[d][1];
                if(ni>=0 and ni<m and nj>=0 and nj<n){
                    int effort=abs(heights[ni][nj]-heights[i][j]);
                    int maxeffort=max(effort,diff);
                    if(maxeffort<dist[ni][nj]){
                        dist[ni][nj]=maxeffort;
                        pq.push({dist[ni][nj],{ni,nj}});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};