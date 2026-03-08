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
  int n,m;
  cin>>n>>m;
  vector<int>a(n),b(m);
  for(auto &i:a) cin>>i;
  for(auto &i:b) cin>>i;
  vector<vector<int>>dp(n+1,vector<int>(m+1,0));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i-1]==b[j-1]){
        dp[i][j]=1+dp[i-1][j-1];
      }else{
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }
  cout<<dp[n][m]<<endl;
  // backtrack on dp table
  int i=n,j=m;
  vector<int>ans;
  while(i>0 && j>0){
    if(a[i-1]==b[j-1]){
      ans.push_back(a[i-1]);
      i--;j--;
    }else{
      if(dp[i-1][j]>dp[i][j-1]){
        i--;
      }else j--;
    }
  }
  reverse(ans.begin(),ans.end());
  for(auto &i:ans)cout<<i<<" ";
  cout<<endl;
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