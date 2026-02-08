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
  ll a,b;
  cin>>a>>b;
  int bitA=-1,bitB=-1;
  int count_a=__builtin_popcountll(a);
  int count_b=__builtin_popcountll(b);
  if(count_a!=count_b){
    cout<<-1<<endl;
    return;
  }
  for(int bit=0;bit<64;bit++){
    if((a&(1LL<<bit))){
      bitA=bit;
      break;
    }
  }
  for(int bit=0;bit<64;bit++){
    if((b&(1LL<<bit))){
      bitB=bit;
      break;
    }
  }
  if((b>>bitB)!=(a>>bitA)){
    cout<<-1<<endl;
    return;
  }
  int trailing_zero=abs(bitA-bitB);
  int ans=0;
  int by3=(trailing_zero/3);
  ans+=by3;
  trailing_zero%=3;
  int by2=(trailing_zero/2);
  ans+=by2;
  trailing_zero%=2;
  ans+=trailing_zero;
  cout<<ans<<endl;
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