#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl "\n"

const ll INFLL = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

// ---------- PBDS (Ordered Set) ----------
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// pbds s; s.find_by_order(k) → k-th element; s.order_of_key(x) → rank of x

// ---------- Utility functions ----------
ll gcd(ll a, ll b){
  return b==0?a:gcd(b,a%b);
}

ll lcm(ll a, ll b){
  return a/gcd(a,b)*b;
}

ll binpow(ll a, ll b, ll mod=MOD){
  ll res=1;
  a%=mod;
  while(b>0){
    if(b&1)res=(res*a)%mod;
    a=(a*a)%mod;
    b>>=1;
  }
  return res;
}

bool isPrime(ll n){
  if(n<=1)return false;
  if(n<=3)return true;
  if(n%2==0||n%3==0)return false;
  for(ll i=5;i*i<=n;i+=6){
    if(n%i==0||n%(i+2)==0)return false;
  }
  return true;
}

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
void solve(Combinatorics &combi){
  string s;
  cin>>s;
  ll remove=0LL;
  ll seq=1LL;
  int len=1;
  for(int i=1;i<s.size();i++){
    if(s[i]==s[i-1]) len++;
    else{
      remove+=(len-1);
      seq=(seq*(len))%998244353;
      len=1;
    }
  }
  remove+=(len-1);
  seq=(seq*(len))%998244353;
  seq=(seq*combi.fact[remove])%998244353;
  cout<<remove<<" "<<seq<<endl;
}

// ---------- Main ----------
int main(){
  Combinatorics combi(2e5+5,998244353);
  fastio;
  int t;
  cin>>t;
  while(t--){
    solve(combi);
  }
  return 0;
}