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
  int n,k;
  cin>>n>>k;
  vector<vector<ll>>dp(k+1,vector<ll>(n+1));
  // State definition:dp[i][last]=number of good subsequence that can be generated.
  // if all indices till i-1 have been filled and the last value filled=last
  // base case
  for(int last=1;last<=n;last++) dp[k][last]=1LL;

  for(int i=k-1;i>=0;i--){
    for(int last=1;last<=n;last++){
      // dp[i][last]=dp[i+1][last]+dp[i+1][last*2].....
      for(int curr=last;curr<=n;curr+=last){
        dp[i][last]=(dp[i][last]+dp[i+1][curr])%MOD;
      }

    }
  }
  // final subproblem
  cout<<dp[0][1]<<endl;
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