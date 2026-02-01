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
vector<int> factors(int n){
  vector<int>ans;
  for(int i=1;i*i<=n;i++){
    if(n%i==0){
      ans.push_back(i);
      if(n/i!=i){
        ans.push_back(n/i);
      }
    }
  }
  return ans;
}
// ---------- Write solution here ----------
void solve() {
  int n;
  cin>>n;
  vector<int>v(n);
  vector<int>s(n+1);
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    s[x]=1;
  }
  vector<ll>dp(n+1,INT_MAX/10);
  for(int i=1;i<=n;i++){
    if(s[i]){
      dp[i]=1;
      continue;
    }
    vector<int>fact=factors(i);
    for(auto &f:fact){
      if(s[f]){
        dp[i]=min(dp[i],1+dp[i/f]);
      }
    }
  }
  for(int i=1;i<=n;i++){
    cout<<((dp[i]>=INT_MAX/10)? -1:dp[i])<<" ";
  }
  cout<<endl;
}

// ---------- Main ----------
int main() {
  fastio;

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}