#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

const int N = 1e6 + 1;
const ll mod = 1e9 + 7;

vector<ll> fact(N), iFact(N);

ll mul(ll a, ll b) {
  return (a % mod * b % mod) % mod;
}

ll binaryExpo(ll a, ll b) {
  ll ans = 1;
  a %= mod;
  while (b) {
      if (b & 1) ans = mul(ans, a);
      a = mul(a, a);
      b >>= 1;
  }
  return ans;
}

void fillVectors() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
      fact[i] = mul(i, fact[i - 1]);
  }

  iFact[N - 1] = binaryExpo(fact[N - 1], mod - 2);

  for (int i = N - 2; i >= 0; i--) {
    iFact[i] = mul(i + 1, iFact[i + 1]);
  }
}

ll nCr(ll n, ll r) {
  if (r < 0 || r > n) return 0;
  return mul(fact[n], mul(iFact[r], iFact[n - r]));
}

void solve() {
  ll a, b;
  cin >> a >> b;
  cout << nCr(a, b) << '\n';
}

int main() {
  fastio;
  fillVectors();

  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}