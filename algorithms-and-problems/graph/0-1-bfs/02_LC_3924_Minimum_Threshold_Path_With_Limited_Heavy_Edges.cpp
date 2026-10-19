class Solution {
using pii=pair<int,int>;
public:
    bool bfs(vector<vector<pii>>&adj,int mid,int source,int target,int k){
        int n=adj.size();
        vector<int>dis(n,1e9);
        dis[source]=0;
        deque<int>dq;
        dq.push_front(source);
        while(!dq.empty()){
            int node=dq.front();
            dq.pop_front();
            for(auto &it:adj[node]){
                int neigh=it.first;
                int w=it.second;
                int cost=(w>mid);
                if(dis[node]+cost<dis[neigh]){
                    dis[neigh]=dis[node]+cost;
                    if(cost==0){
                        dq.push_front(neigh);
                    }else dq.push_back(neigh);
                }
            }
        }
        return dis[target]<=k;
    }
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        if(source==target) return 0;
        vector<vector<pii>>adj(n);
        int maxi=0;
        for(int i=0;i<(int)edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            maxi=max(maxi,w);
        }
        if(!bfs(adj,maxi,source,target,k)){
            return -1;
        }
        int lo=0,hi=maxi;
        int ans=hi;
        while(lo<=hi){
            int mid=(lo+(hi-lo)/2);
            if(bfs(adj,mid,source,target,k)){
                ans=min(ans,mid);
                hi=mid-1;
            }else lo=mid+1;
        }
        return ans;
    }
};