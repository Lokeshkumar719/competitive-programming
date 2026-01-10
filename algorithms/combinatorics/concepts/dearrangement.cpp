#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
const int MOD = 1e9 + 7;

class Combinatorics {
public:
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

ll derrangment(ll n,Combinatorics &combi){
  ll ans=0;
  ll sign=1;
  ll nfact=combi.fact[n];
  for(ll i=2;i<=n;i++){
    ll val= (nfact*combi.invfact[i])%MOD;
    // remember to add MOD while taking mod in case of (a-b)%m
    ans=(ans+sign*val+MOD)%MOD;
    sign*=-1;
  }
  return ans;
}

// ---------- Main ----------
int main() {
  fastio;
  int n;
  cin>>n;
  Combinatorics combi(1e6,MOD);
  ll ans=derrangment(n,combi);
  cout<<ans<<endl;
  return 0;
}