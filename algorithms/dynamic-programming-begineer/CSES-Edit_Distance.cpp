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
  string a,b;
  cin>>a>>b;
  int n=a.size();
  int m=b.size();
  // state of dp dp[i][j]=edit distance of a[i ... n-1] ans b[j ... m-1]
  // ans=dp[0][0]

  // transition=dp[i][j]==dp[i+1][j+1] if a[i]=b[j]
  // else dp[i][j]=min(dp[i][j+1],dp[i+1][j],dp[i+1][j+1])
  vector<ll>next(m+1);
  for(int i=0;i<=m;i++)next[i]=ll(m-i);
  for(int i=n-1;i>=0;i--){
    vector<ll>curr(m+1);
    curr[m]=n-i;
    for(int j=m-1;j>=0;j--){
      if(a[i]==b[j]){
        curr[j]=next[j+1];
      }else{
        curr[j]=1+min({next[j],curr[j+1],next[j+1]});
      }
    }
    next=curr;
  }
  cout<<next[0]<<endl;  
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