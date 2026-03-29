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

// ---------- Write solution here ----------
void solve(){
  int n;
  cin>>n;
  vector<vector<int>>v;
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    vector<int>temp(k);
    for(auto &i:temp) cin>>i;
    v.push_back(temp);
  }
  // store the power requried to pass individual cave and number of monters in that cave
  vector<pii>power_for_each_cave;
  for(int i=0;i<n;i++){
    int m=v[i].size();
    int maxi=INT_MIN;
    for(int j=0;j<m;j++){
      maxi=max(v[i][j]-j,maxi);
    }
    power_for_each_cave.push_back({1+maxi,m});
  }
  sort(power_for_each_cave.begin(),power_for_each_cave.end());
  ll sum=0LL;
  ll ans=LLONG_MIN;
  for(int i=0;i<power_for_each_cave.size();i++){
    ans=max(ans,power_for_each_cave[i].first-sum);
    sum+=power_for_each_cave[i].second;
  }
  cout<<ans<<endl;
}

// ---------- Main ----------
int main(){
  fastio;
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}