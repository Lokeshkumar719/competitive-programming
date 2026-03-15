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
bool isValid(int prev,int m){
  return prev>=1 && prev<=m;
}
// ---------- Write solution here ----------
void solve(){
  int n,m;
  cin>>n>>m;
  vector<int>v(n);
  for(auto &i:v) cin>>i;
  vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
  // dp[i][k]=number of prefix of length i such that last element of prefix is k

  // base case
  for(int k=1;k<=m;k++){
    dp[1][k]=((v[0]==0 || v[0]==k)? 1:0);
  }

  // transition
  // dp[i][k]=dp[i-1][k-1]+dp[i-1][k]+dp[i-1][k+1]

  for(int i=2;i<=n;i++){
    for(int k=1;k<=m;k++){
      if(v[i-1]!=0 && v[i-1]!=k){
        dp[i][k]=0LL;
        continue;
      }
      for(int prev=k-1;prev<=k+1;prev++){
          if(isValid(prev,m)){
            dp[i][k]=(dp[i][k]+dp[i-1][prev])%MOD;
          }
      }
    }
  }
  ll ans=0;
  for(int k=1;k<=m;k++){
    ans=(ans+dp[n][k])%MOD;
  }
  cout<<ans<<endl;
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