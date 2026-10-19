class Solution {
public:
    using ll = long long;
    using pll = pair<ll,ll>;
    // we should use topo sort to find the shortest path because we have directed graph for better complexity
    bool check(vector<vector<pair<int,int>>> &adj,ll mid,vector<bool>& online,ll k){
        int n = online.size();
        vector<ll> dist(n,1e18);
        dist[0] = 0;
        priority_queue<pll,vector<pll>,greater<pll>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [node,dis] = pq.top();
            pq.pop();

            if(dis > dist[node])
                continue;

            if(node == (n-1))
                return true;

            for(auto &[neigh,wt] : adj[node]){
                if(!online[neigh])
                    continue;

                if(wt < mid || dis + wt > k)
                    continue;

                if(dis + wt < dist[neigh]){
                    dist[neigh] = dis + wt;
                    pq.push({neigh,dis + wt});
                }

            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        ll lo = 0;
        ll hi = 1e18;
        ll ans = -1;
        while(lo <= hi){
            ll mid = lo + (hi - lo)/2;
            if(check(adj,mid,online,k)){
                ans = mid;
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        return ans;
    }
};