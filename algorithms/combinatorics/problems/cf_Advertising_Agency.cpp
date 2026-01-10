#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD=1e9+7;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

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
  int n,k;
  cin>>n>>k;
  vector<int>v(n);
  for(auto &i:v) cin>>i;
  sort(v.begin(),v.end(),[](int a,int b){
    return a>=b;
  });
  // calculate the frequency of each element for 1st k elements(which will tell how much each element is required)
  map<int,int>mp1;
  for(int i=0;i<k;i++) mp1[v[i]]++;
  
  // choose the required elements number from available
  map<int,int>mp2;
  for(auto &ele:v) mp2[ele]++;

  ll ans=1;
  for(auto &it:mp2){
    int ele=it.first;
    int freq=it.second;
    if(mp1.count(ele)){
      ans=(ans*combi.nCr(freq,mp1[ele]))%MOD;
    }
  }
  cout<<ans<<endl;
}

// ---------- Main ----------
int main() {
  fastio;
  int t;
  cin >> t;
  Combinatorics combi(1000,MOD);
  while (t--) {
    solve(combi);
  }
  return 0;
}