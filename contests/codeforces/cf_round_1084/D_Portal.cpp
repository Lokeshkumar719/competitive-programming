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
  int n,x,y;
  cin>>n>>x>>y;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  vector<int>mid,left_right;
  for(int i=0;i<x;i++){
    left_right.push_back(v[i]);
  }
  for(int i=x;i<y;i++){
    mid.push_back(v[i]);
  }
  for(int i=y;i<n;i++){
    left_right.push_back(v[i]);
  }
  auto it=min_element(mid.begin(),mid.end());
  rotate(mid.begin(),it,mid.end());
  int idx=left_right.size();
  for(int i=0;i<left_right.size();i++){
    if(left_right[i]>mid.front()){
      idx=i;
      break;
    }
  }
  for(int i=0;i<idx;i++){
    cout<<left_right[i]<<" ";
  }
  for(int i=0;i<mid.size();i++){
    cout<<mid[i]<<" ";
  }
  for(int i=idx;i<left_right.size();i++){
    cout<<left_right[i]<<" ";
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