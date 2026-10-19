class Solution {
public:
    // dist[i][x] => dist to reach d with concatenation of x same characters
    // answers is min of(dist[n-1][0] ... dist[n-1][k])
    using pip = pair<int, pair<int, int>>;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& it : edges)
            adj[it[0]].push_back({it[1], it[2]});

        vector<vector<int>> dist(n,vector<int>(k+1,1e9));
        for (int i = 1; i <= k; i++)
            dist[0][i] = 0;

        priority_queue<pip, vector<pip>, greater<pip>> pq;
        pq.push({0,{0,1}});
        while (!pq.empty()) {
            auto [dis, pip] = pq.top();
            auto [u, numChar] = pip;
            pq.pop();
           
            if (dist[u][numChar] != dis)
                continue;
            for (auto& [v, wt] : adj[u]) {
                int newDis = dis + wt;
                int newNumChar = (labels[v] == labels[u]) ? numChar + 1 : 1;
                if (newNumChar > k)
                    continue;
                if (dist[v][newNumChar] > newDis) {
                    dist[v][newNumChar] = newDis;
                    pq.push({newDis, {v, newNumChar}});
                }
            }
        }

        int ans = 1e9;
        for (int i = 1; i <= k; i++) {
            ans = min(ans, dist[n - 1][i]);
        }

        return (ans != 1e9) ? ans : -1;
    }
};