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

const ll INFLL = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

// ---------- PBDS (Ordered Set) ----------
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds; // find_by_order(k), order_of_key(x)

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
  ll n,k,x;
  cin>>n>>k>>x;
  vector<ll>v(n);
  for(auto &i:v) cin>>i;
  sort(v.begin(),v.end());
  vector<ll>diff;
  for(int i=1;i<n;i++){
    if((v[i]-v[i-1])>x){
      diff.push_back(v[i]-v[i-1]);
    }
  }
  sort(diff.begin(),diff.end());
  ll cnt=diff.size()+1;
  for(int i=0;i<diff.size();i++){
    ll reqd=((diff[i]/x+(diff[i]%x!=0))-1);
    if(k>=reqd){
      k-=reqd;
      cnt--;
    }else break;
  }
  cout<<cnt<<endl;
}

// ---------- Main ----------
int main(){
  fastio;
  int t=1;
  while(t--){
    solve();
  }
  return 0;
}