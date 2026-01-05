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

  int n;
  cin>>n;
  ll div_cnt1=1,div_sum=1,div_prod=1,div_cnt2=1;
  while(n--){
    ll p,k;
    cin>>p>>k;  
    div_sum=( (((div_sum%MOD) *(binpow(p,k+1)-1))%MOD) *(binpow(p-1,MOD-2))%MOD)%MOD;
    div_prod=( (binpow(div_prod,k+1))*(binpow( binpow(p,(k*(k+1))/2),div_cnt2)) )%MOD;
    div_cnt1=((div_cnt1%MOD)*(k+1)%MOD)%MOD;
    div_cnt2=(((div_cnt2%(MOD-1))*(k+1)%(MOD-1))%(MOD-1));
  }
  cout<<div_cnt1<<" "<<div_sum<<" "<<div_prod;
  return 0;
}