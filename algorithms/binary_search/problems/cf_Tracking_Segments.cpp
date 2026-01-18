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
bool check(vector<pair<int,int>>&segments,vector<int>queries,int mid,int n){
  vector<int>arr(n,0);
  // create the array
  for(int i=0;i<mid;i++){
    arr[queries[i]]=1;
  }
  // take the prefix sum
  for(int i=1;i<n;i++){
    arr[i]+=arr[i-1];
  }
  // check if any  segment became beautiful
  for(auto &i:segments){
    int l=i.first;
    int r=i.second;
    int len=r-l+1;
    int num_one=(arr[r]- ((l-1>=0)? arr[l-1]:0));
    if(num_one>(len/2)) return true;
  }
  return false;
}
// ---------- Write solution here ----------
void solve() {
  int n,m;
  cin>>n>>m;
  vector<pair<int,int>>segments(m);
  for(auto &i:segments){
    cin>>i.first;
    cin>>i.second;
    i.first--;
    i.second--;
  }
  int q;
  cin>>q;
  vector<int>queries(q);
  for(auto &i:queries){
    cin>>i;
    i--;
  }
  int lo=1,hi=q;
  int ans=-1;
  while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(check(segments,queries,mid,n)){
      ans=mid;
      hi=mid-1;
    }else{
      lo=mid+1;
    }
  }
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