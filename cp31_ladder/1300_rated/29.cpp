#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int red=0,white=0;
void dfs(int node,int color,vector<list<int>>&adj,vector<int>&vis){
  vis[node]=1;
  if(color==0) white++;
  else red++;
  for(auto &neigh:adj[node]){
    if(!vis[neigh]){
      dfs(neigh,1-color,adj,vis);
    }
  }
}
void solve() {
  int n;
  cin>>n;
  vector<list<int>>adj(n+1);
  for(int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int>vis(n+1);
  dfs(1,0,adj,vis);
  cout<<red*white-(n-1);
}
int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}

// Color the graph