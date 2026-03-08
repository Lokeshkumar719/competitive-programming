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
  vector<int>x(n),y(n);
  for(auto &i:x) cin>>i;
  for(auto &i:y) cin>>i;
  vector<int>pos,neg;
  for(int i=0;i<n;i++){
    if(y[i]-x[i]<0){
      neg.push_back(y[i]-x[i]);
    }else pos.push_back(y[i]-x[i]);
  }
  int i=0,j=0;
  int cnt=0;
  sort(neg.begin(),neg.end());
  sort(pos.begin(),pos.end(),[](int a,int b){
    return a>b;
  });
  while(i<neg.size() && j<pos.size()){
    if(neg[i]+pos[j]>=0){
      i++;
      j++;
      cnt++;
    }else i++;
  }
  if(j<(int)pos.size()){
    cnt+=((int)pos.size()-j)/2;
  }
  cout<<cnt<<endl;
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