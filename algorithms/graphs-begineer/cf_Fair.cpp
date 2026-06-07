#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl "\n"

const ll INFLL = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

// ---------- PBDS (Ordered Set) ----------
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// pbds s; s.find_by_order(k) → k-th element; s.order_of_key(x) → rank of x

// ---------- DSU ----------
class DSU{
private:
  vector<int>parent,size;

public:
  DSU(int n){
    parent.resize(n+1);
    size.resize(n+1,1);

    for(int i=0;i<=n;i++){
      parent[i]=i;
    }
  }

  int findUPar(int node){
    if(node==parent[node]){
      return node;
    }

    return parent[node]=findUPar(parent[node]);
  }

  void unionBySize(int u,int v){
    int pu=findUPar(u);
    int pv=findUPar(v);

    if(pu==pv){
      return;
    }

    if(size[pu]<size[pv]){
      parent[pu]=pv;
      size[pv]+=size[pu];
    }
    else{
      parent[pv]=pu;
      size[pu]+=size[pv];
    }
  }

  bool sameComponent(int u,int v){
    return findUPar(u)==findUPar(v);
  }

  int componentSize(int node){
    return size[findUPar(node)];
  }
};

// ---------- Utility functions ----------
ll gcd(ll a, ll b){
  return b==0?a:gcd(b,a%b);
}

ll lcm(ll a, ll b){
  return a/gcd(a,b)*b;
}

ll binpow(ll a, ll b, ll mod=MOD){
  ll res=1;
  a%=mod;
  while(b>0){
    if(b&1)res=(res*a)%mod;
    a=(a*a)%mod;
    b>>=1;
  }
  return res;
}

bool isPrime(ll n){
  if(n<=1)return false;
  if(n<=3)return true;
  if(n%2==0||n%3==0)return false;
  for(ll i=5;i*i<=n;i+=6){
    if(n%i==0||n%(i+2)==0)return false;
  }
  return true;
}

// ---------- Write solution here ----------
void solve(){
  ll n,m,k,s;
  cin>>n>>m>>k>>s;
  vector<ll>good_types(n);
  for(ll i=0;i<n;i++){
    cin>>good_types[i];
    good_types[i]--;
  }
  vector<vector<ll>>adj(n);
  for(ll i=0;i<m;i++){
    ll u,v;
    cin>>u>>v;
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<vector<ll>>dist(k,vector<ll>(n,1e9));
  for(ll t=0;t<k;t++){
    // run multisource bfs
    queue<ll>q;
    ll good_type=t;
    for(ll town=0;town<n;town++){
      if(good_types[town]==good_type){
        q.push(town);
        dist[t][town]=0LL;
      }
    }
    // bfs to fill dist matrix
    while(!q.empty()){
      ll town=q.front();q.pop();
      for(auto &neigh:adj[town]){
        if(dist[t][neigh]>(dist[t][town]+1LL)){
          dist[t][neigh]=dist[t][town]+1LL;
          q.push(neigh);
        }
      }
    }
  }
  vector<ll>ans;
  for(ll town=0;town<n;town++){
    vector<ll>temp;
    for(ll t=0;t<k;t++){
      temp.push_back(dist[t][town]);
    }
    ll sum=0LL;
    sort(temp.begin(),temp.end());
    for(ll i=0;i<s;i++){
      sum+=(temp[i]);
    }
    ans.push_back(sum);
  }
  for(auto &i:ans){
    cout<<i<<" ";
  }
  cout<<endl;
}

// ---------- Main ----------
int main(){
  fastio;
  int t=1;
  while(t--){
    solve();
  }
  return 0;
}
