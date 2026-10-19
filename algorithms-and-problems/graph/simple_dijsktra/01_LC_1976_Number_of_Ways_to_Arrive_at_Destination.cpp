class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        vector<list<pair<long long,long long >>>adj(n);
        for(auto &v:roads){
            adj[v[0]].push_back({v[1],v[2]});
            adj[v[1]].push_back({v[0],v[2]});
        }
        vector<long long >ways(n,0);
        vector<long long>dist(n, LLONG_MAX);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            int city=pq.top().second;
            long long dis=pq.top().first;
            pq.pop();
            for(auto &it:adj[city]){
                int neigh=it.first;
                long long gap=it.second;

                if(dis+gap>dist[neigh]) continue;

                if(gap+dis<dist[neigh]){
                    dist[neigh]=gap+dis;
                    ways[neigh]=ways[city];
                    pq.push({dist[neigh],neigh});
                }
                else if(gap+dis==dist[neigh]){
                    ways[neigh]=(ways[neigh]+ways[city])%mod;
                }
            }
        }
        long long cnt=ways[n-1];
        return cnt%mod;
    }
};