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
const int MOD = 998244353;

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

// ---------- Write solution here ----------
void solve(Combinatorics &combi) {
  int n;
  cin>>n;
  vector<int>v(n);
  for(auto &i:v)cin>>i;
  sort(v.begin(),v.end());
  int maxi=v[n-1];
  int smaxi=v[n-2];
  if(maxi==smaxi){
    cout<<combi.fact[n]<<endl;
    return;
  }else if((maxi-smaxi)>1){
    cout<<0<<endl;
    return;
  }
  ll freq=0;
  for(int i=n-2;i>=0;i--){
    if(v[i]==smaxi){
      freq++;
    }else break;
  }
  ll ans=0;
  for(ll seats=freq;seats<n;seats++){
    ans=(ans+combi.nCr(seats,freq))%MOD;
  }
  ans=(ans*(combi.fact[freq]))%MOD;
  ans=(ans*(combi.fact[n-freq-1]))%MOD;
  cout<<(combi.fact[n]-ans+MOD)%MOD<<endl;
}

// ---------- Main ----------
int main() {
  fastio;
  Combinatorics combi(2*1e5+1,998244353);
  int t;
  cin >> t;
  while (t--) {
    solve(combi);
  }

  return 0;
}