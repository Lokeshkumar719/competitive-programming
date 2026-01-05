#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD=1e9+7;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

class Combinatorics {
private:
  ll MOD;
  int MAXN;
  vector<ll> fact, invfact;

  ll binexp(ll a, ll b) {
    ll res = 1;
    while (b) {
      if (b & 1) res = (res * a) % MOD;
      a = (a * a) % MOD;
      b >>= 1;
    }
    return res;
  }

public:
  // Constructor
  Combinatorics(int maxn, ll mod) {
    MAXN = maxn;
    MOD = mod;
    fact.resize(MAXN + 1);
    invfact.resize(MAXN + 1);
    precompute();
  }

  void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
      fact[i] = (fact[i - 1] * i) % MOD;

    invfact[MAXN] = binexp(fact[MAXN], MOD - 2);
    for (int i = MAXN - 1; i >= 0; i--)
      invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
  }

  ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
  }
};

// ---------- Main ----------
int main() {
  fastio;
  Combinatorics combi(2*1e6+1,1e9+7);
  int n;
  cin>>n;
  ll cnt=combi.nCr(2*n-1,n);
  cnt=(2%MOD*cnt%MOD)%MOD;
  ll ans=cnt-n;
  cout<<ans;
  return 0;
}