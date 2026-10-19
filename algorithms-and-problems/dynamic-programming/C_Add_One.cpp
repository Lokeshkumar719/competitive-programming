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
#define endl "\n";

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
vector<vector<ll>> solve(){
  int maxM=2e5+5;
  vector<vector<ll>>dp(maxM+1,vector<ll>(10,0LL));
  for(int j=0;j<10;j++) dp[0][j]=1LL;
  for(int i=1;i<=maxM;i++){
    for(int j=0;j<9;j++){
      dp[i][j]=(dp[i-1][j+1])%MOD;
    }
    dp[i][9]=(dp[i-1][0]+dp[i-1][1])%MOD;
  }
  return dp;
}

// ---------- Main ----------
int main(){
  fastio;
  vector<vector<ll>>dp=solve();
  int t;
  cin>>t;
  while(t--){
    string n;
    cin>>n;
    int m;
    cin>>m;
    ll ans=0LL;
    for(int i=0;i<n.size();i++){
      ans=(ans+dp[m][n[i]-'0'])%MOD;
    }
    cout<<ans<<endl;
  }
  return 0;
}