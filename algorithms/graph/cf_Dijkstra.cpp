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
  ll n,m;
  cin>>n>>m;
  vector<vector<pll>>adj(n+1);
  for(int i=0;i<m;i++){
    ll u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  priority_queue<pll,vector<pll>,greater<pll>>pq;
  vector<ll>dist(n+1,INFLL);
  vector<ll>par(n+1,-1);
  pq.push({0LL,1LL});
  dist[1]=0LL; par[1]=1LL;
  while(!pq.empty()){
    ll dis=pq.top().first;
    ll curr=pq.top().second;
    pq.pop();
    if(dis>dist[curr]) continue;
    for(auto &neigh:adj[curr]){
      ll v=neigh.first;
      ll w=neigh.second;
      ll newDis=dist[curr]+w;
      if(newDis<dist[v]){
        dist[v]=newDis;
        pq.push({newDis,v});
        par[v]=curr;
      }
    }
  }
  if(dist[n]==INFLL){
    cout<<-1<<endl;
    return;
  }
  vector<ll>ans;
  ll i=n;
  while(par[i]!=i){
    ans.push_back(i);
    i=par[i];
  }
  ans.push_back(1);
  for(ll i=((ll)ans.size()-1);i>=0;i--){
    cout<<ans[i]<<" ";
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