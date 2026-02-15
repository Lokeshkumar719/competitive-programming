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
  vector<int>a(n),b(n);
  for(auto &i:a) cin>>i;
  for(auto &i:b) cin>>i;
  int first=-1,last=-1;
  for(int i=0;i<n;i++){
    if(a[i]!=b[i]){
      if(first==-1){
        first=i;
      }else last=i;
    }
  }
  // check if we can extend to the left
  int i=first-1;
  while(i>=0){
    if(b[i]<=b[i+1]) i--;
    else break;
  }
  int start=i+1;
  if(last==-1){
    last=n-1;
  }// check if we can extend to the right
  int j=last+1;
  while(j<n){
    if(b[j]>=b[j-1])j++;
    else break;
  }
  int end=j-1;
  cout<<start+1<<" "<<end+1<<endl;
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