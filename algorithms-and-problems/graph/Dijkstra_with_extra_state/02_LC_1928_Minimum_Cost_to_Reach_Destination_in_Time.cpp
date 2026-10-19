class Solution {
using state=pair<int,pair<int,int>>;
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        const int INF=1e9;
        vector<vector<int>>cost(n,vector<int>(maxTime+1,INF));
        // push {fee,{node,time}}
        priority_queue<state,vector<state>,greater<state>>pq;
        cost[0][0]=passingFees[0];
         pq.push({cost[0][0],{0,0}});
        while(!pq.empty()){
            int fee=pq.top().first;
            int node=pq.top().second.first;
            int time=pq.top().second.second;
            if(node==(n-1)) return cost[node][time];
            pq.pop();
            if(cost[node][time]!=fee) continue;
            for(auto &it:adj[node]){
                int neigh=it.first;
                int t=it.second;
                int newTime=time+t;
                if(newTime>maxTime) continue;
                if((fee+passingFees[neigh])<cost[neigh][newTime]){
                    cost[neigh][newTime]=fee+passingFees[neigh];
                    pq.push({cost[neigh][newTime],{neigh,newTime}});
                }
            }
        }

        int ans=INF;
        for(int t=0;t<=maxTime;t++){
            ans=min(ans,cost[n-1][t]);
        }
        return (ans!=INF)? ans:-1;
    }
};