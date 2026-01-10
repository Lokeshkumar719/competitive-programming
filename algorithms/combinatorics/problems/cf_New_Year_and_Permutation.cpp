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
// ---------- Main ----------
int main() {
  fastio;
  int n,m;
  cin>>n>>m;
  vector<ll>fact(n+1,1);
  for(int i=1;i<=n;i++){
    fact[i]=((fact[i-1])*i)%m;
  }
  ll ans=0;
  for(int d=0;d<n;d++){
    // in how many ways we can make differnce=d;
    ll diffWays=(n-d)%m;
    // how many (l,r) for difference=d;
    ll pairs=(n-d)%m;
    // permutation of elements of i (l,r) pair
    ll permute=fact[d+1];
    // permutations of rest of elements
    ll restPermute=fact[n-(d+1)];
    // total permutation for difference d
    ll total=(((((diffWays*pairs)%m)*permute)%m)*restPermute)%m;
    // add in final and
    ans=(ans+total)%m;
  }
  cout<<ans<<endl;
  return 0;
}