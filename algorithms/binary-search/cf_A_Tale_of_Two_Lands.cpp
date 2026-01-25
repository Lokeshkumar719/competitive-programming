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
  int n;
  cin>>n;
  vector<ll>v(n);
  for(auto &i:v){
    cin>>i;
    i=abs(i);
  }
  sort(v.begin(),v.end());
  ll ans=0;
  for(ll i=0;i<n;i++){
    ll ele=v[i];
    ll idx_of_twice=upper_bound(v.begin(),v.end(),2*ele)-v.begin();
    idx_of_twice--;
    ans+=(idx_of_twice-i);
  }
  cout<<ans<<endl;
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