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
  int n,m,h;
  cin>>n>>m>>h;
  vector<ll>a(n);
  for(auto &i:a) cin>>i;
  vector<ll>temp=a;
  vector<pair<ll,ll>>bc(m);
  for(auto &i:bc){
    cin>>i.first;
    i.first--;
    cin>>i.second;
  }
  set<int>s;
  for(int i=0;i<m;i++){
    int idx=bc[i].first;
    int ele=bc[i].second;
    a[idx]+=ele;
    s.insert(idx);
    if(a[idx]>h){
      for(auto &idx:s){
        a[idx]=temp[idx];
      }
      s.clear();
    }
  }
  for(auto &i:a){
    cout<<i<<" ";
  }
  cout<<endl;

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