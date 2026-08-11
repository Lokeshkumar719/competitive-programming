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

bool bfs(vector<int>&color,vi &node_cnt,vector<vector<int>>&adj,int node){
  queue<int>q;
  q.push(node);
  color[node]=0;
  node_cnt[0]++;
  while(!q.empty()){
    int curr=q.front();q.pop();
    for(auto &i:adj[curr]){
      if(color[i]==-1){
        q.push(i);
        color[i]=color[curr]^1;
        node_cnt[color[i]]++;
      }else if(color[i]==color[curr]){
        return false;
      }
    }
  }
  return true;
} 

// ---------- Write solution here ----------
void solve(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>>adj(n+1);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  vector<int>color(n+1,-1);
  ll mod=998244353;
  ll ans=1LL;
  for(int i=1;i<=n;i++){
    if(color[i]==-1){
      vi node_cnt(2,0);
      if(!bfs(color,node_cnt,adj,i)){
        cout<<0<<endl;
        return;
      }
      ll result=0LL;
      ll cnt1=binpow(2LL,(ll)node_cnt[0],mod);
      ll cnt2=binpow(2LL,(ll)node_cnt[1],mod);
      result=(cnt1+cnt2)%mod;
      ans=(ans*result)%mod;
    }
  }
  cout<<ans<<endl;
}

// ---------- Main ----------
int main(){
  fastio;
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}