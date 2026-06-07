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
  ll n,m,k;
  cin>>n>>m>>k;
  vll v(n);
  for(auto &i:v) cin>>i;

  ll max_pair=0;
  for(ll i=0;i<n;i++){
    if(v[i]>=k){
      max_pair+=(v[i]/k);
    }
  }
  ll possible_pairs=m/(k+1);
  ll mini=min(max_pair,possible_pairs);
  ll ans=mini*k;
  ll left=m-(mini*(k+1));
  if(left==0){
    cout<<ans<<endl;
    return;
  }
  sort(v.begin(),v.end(),greater<int>());
  int i=0;
  while(mini>0){
    ll pairs=v[i]/(k);
    if(pairs<=mini){
      v[i]-=(pairs*k);
      mini-=pairs;
    }else{
      v[i]-=mini*k;
      break;
    }
    i++;
  }
  sort(v.begin(),v.end(),greater<int>());
  for(ll i=0;i<n && left>0;i++){
    if(v[i]<=left){
      left-=(v[i]+1);
      ans+=v[i];
    }else{
      ans+=left;
      left=0;
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