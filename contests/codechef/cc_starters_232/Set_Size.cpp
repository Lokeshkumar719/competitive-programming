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

// ---------- Main ----------
int main(){
  fastio;
  ll n,q;
  cin>>n>>q;
  vector<ll>v;
  set<ll>s;
  for(int i=0;i<n;i++){
    ll temp;
    cin>>temp;
    if(!s.count(temp)){
      v.push_back(temp);
    }
  }
  sort(v.begin(),v.end());
  vector<ll>gaps;
  for(int i=1;i<v.size();i++){
    gaps.push_back(v[i]-v[i-1]);
  }
  sort(gaps.begin(),gaps.end());
  int x=gaps.size();
  vector<ll>pref(x+1,0);
  for(int i=0;i<x;i++){
    pref[i+1]=pref[i]+gaps[i];
  }
  while(q--){
    int x;
    cin>>x;
    int idx=lower_bound(gaps.begin(),gaps.end(),x)-gaps.begin();
    int cnt=(int)v.size()-idx;
    ll ans=0LL;
    ans+=(ll)((ll)cnt)*(ll)x;
    ans+=(pref[idx]);
    cout<<ans<<endl;
  }
  return 0;
}