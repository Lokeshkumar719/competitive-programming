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

bool check(vector<pair<double,double>>&v,double time){
  double maxi=-1e18;
  double mini=1e18;
  for(auto &it:v){
    double pos=it.first;
    double speed=it.second;
    double newPos_left=pos-time*speed;
    double newPos_right=pos+time*speed;
    maxi=max(maxi,newPos_left);
    mini=min(mini,newPos_right);
  }
  return (maxi<=mini);
}

// ---------- Write solution here ----------
void solve() {
  int n;
  cin>>n;
  vector<pair<double,double>>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i].first>>v[i].second;
  }
  double lo=0,hi=1e9;
  double ans=hi;
  for(int i=0;i<60;i++){
    double mid=(lo+hi)/2;
    if(check(v,mid)){
      ans=min(ans,mid);
      hi=mid;
    }else lo=mid;
  }
  cout<<fixed<<setprecision(7)<<ans<<endl;
}

// ---------- Main ----------
int main() {
  fastio;

  int t=1;
  while (t--) {
    solve();
  }

  return 0;
}