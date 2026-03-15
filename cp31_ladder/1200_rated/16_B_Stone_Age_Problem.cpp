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

const ll INFLL = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

// ---------- PBDS (Ordered Set) ----------
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds; // find_by_order(k), order_of_key(x)

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
  ll n,q;
  cin>>n>>q;
  vector<ll>v(n);
  for(auto &i:v) cin>>i;
  map<ll,ll>mp;
  ll sum=accumulate(v.begin(),v.end(),0LL);
  ll arr_val=-1;
  while(q--){
    ll t;
    cin>>t;
    if(t==2){
      ll x;
      cin>>x;
      arr_val=x;
      mp.clear();
      sum=n*x;
    }else{
      ll idx,val;
      cin>>idx>>val;
      if(!mp.count(idx-1) && arr_val==-1){
        sum-=v[idx-1];
        v[idx-1]=val;
      }else if(mp.count(idx-1)){
        sum-=mp[idx-1];
      }else if(arr_val!=-1){
        sum-=arr_val;
      }
      mp[idx-1]=val;
      sum+=val;
    }
    cout<<sum<<endl;
  }
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