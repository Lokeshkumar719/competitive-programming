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
  vector<int>a(n),b(n),c(n);
  for(auto &i:a) cin>>i;
  for(auto &i:b) cin>>i;
  for(auto &i:c) cin>>i;

  // instead of checking for all (i,j,k) pairs you can check only for (1,j,k) pair
  ll cnt1=0;
  for(int i=0;i<n;i++){
    bool flag=true;
    for(int j=0;j<n;j++){
      if(a[j]>=b[(j+i)%n]){
        flag=false;
        break;
      }
    }
    if(flag){
      cnt1++;
    }
  }

  ll cnt2=0;
  for(int i=0;i<n;i++){
    bool flag=true;
    for(int j=0;j<n;j++){
      if(b[j]>=c[(j+i)%n]){
        flag=false;
        break;
      }
    }
    if(flag){
      cnt2++;
    }
  }
  cout<<(cnt1*cnt2*n)<<endl;
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