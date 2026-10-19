#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

const ll INFLL = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

// ---------- Utility functions ----------
ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

ll binpow(ll a, ll b, ll mod = MOD) {
  ll res = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

bool isPrime(ll n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (ll i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  }
  return true;
}

// ---------- Write solution here ----------
void solve() {
  ll n;
  cin>>n;
  vector<string>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  vector<vector<ll>>dp(n,vector<ll>(n,0LL));
  dp[0][0]=(v[0][0]!='*');
  for(int j=1;j<n;j++){
    if(v[0][j]!='*')dp[0][j]=dp[0][j-1];
    else dp[0][j]=0;
  }
  for(int i=1;i<n;i++){
    if(v[i][0]!='*') dp[i][0]=dp[i-1][0];
    else dp[i][0]=0;
  }
  for(int i=1;i<n;i++){
    for(int j=1;j<n;j++){
      if(v[i][j]=='*') dp[i][j]=0LL;
      else dp[i][j]=(dp[i-1][j]%MOD+dp[i][j-1]%MOD)%MOD;
    }
  }
  cout<<dp[n-1][n-1]%MOD<<endl;
}

// ---------- Main ----------
int main() {
  fastio;

  int t=1;
  while (t--) {
    solve();
  }

  return 0;
}