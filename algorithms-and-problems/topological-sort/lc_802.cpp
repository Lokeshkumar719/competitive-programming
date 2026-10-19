class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<bool>& vis,vector<bool>&inRecursion){
        vis[node]=true;
        inRecursion[node]=true;
        for(auto &neigh:adj[node]){
            if(vis[neigh] && inRecursion[neigh]) return true;
            if(!vis[neigh] && dfs(neigh,adj,vis,inRecursion)) return true;
        }
        inRecursion[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(auto &node:graph[i]){
                adj[i].push_back(node);
            }
        }
        vector<bool>vis(n,false);
        vector<bool>inRecursion(n,false);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,inRecursion);
            }
        }
        for(int i=0;i<n;i++){
            if(!inRecursion[i]) ans.push_back(i);
        }
        return ans;
    }
};