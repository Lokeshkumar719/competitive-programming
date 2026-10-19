class Solution {
using pii=pair<int,int>;
public:
    const int INF=1e9;
    void fillQueue(queue<pii>&q,vector<vector<int>>&adj,vector<vector<int>>&dist,int color,int node){
        for(auto &neigh:adj[node]){
            if(dist[neigh][color]==INF){
                dist[neigh][color]=1+dist[node][!color];
                q.push({neigh,color});
            }
        }
    }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>>redAdj(n),blueAdj(n);
        for(auto &e:redEdges) redAdj[e[0]].push_back(e[1]);
        for(auto &e:blueEdges) blueAdj[e[0]].push_back(e[1]);
        
       
        vector<vector<int>>dist(n,vector<int>(2,INF));
        queue<pii>q;
        dist[0][0]=0;dist[0][1]=0;
        // {node,prevColor};
        q.push({0,0});q.push({0,1});
        while(!q.empty()){
            int node=q.front().first;
            int prevColor=q.front().second;
            q.pop();
            (prevColor)? fillQueue(q,redAdj,dist,!prevColor,node):fillQueue(q,blueAdj,dist,!prevColor,node);
        }

        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            ans[i]=min(dist[i][0],dist[i][1]);
            if(ans[i]==INF) ans[i]=-1;
        }

        return ans;
    }
};