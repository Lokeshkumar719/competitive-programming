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
  cin >> n; // Read the number of districts
  vector<int> gang(n + 1); // Vector to store the gang each district belongs to
  for (int i = 1; i <= n; i++)
    cin >> gang[i]; // Read the gang for each district
  vector<array<int, 2>> edges; // Vector to store the edges (roads) between districts

  int val1 = 1, val2 = -1; // Initialize the first two nodes to be connected by an edge
  for (int i = 2; i <= n; i++){
    if (gang[i] != gang[1]){
      edges.push_back({1, i}); // Connect the first district with a different gang district
      val2 = i; // Store the index of the second district
      break;
    }
  }

  if (val2 == -1){
    cout << "NO\n"; // If no different gang is found, output NO
    return;
  }

  for (int i = 2; i <= n; i++){
    if (i == val2)
      continue; // Skip the already connected district

    if (gang[i] != gang[val1]){
      edges.push_back({val1, i}); // Connect with the first district if gangs are different
    }
    else{
      edges.push_back({val2, i}); // Otherwise, connect with the second district
    }
  }
  cout << "YES\n"; // Output YES if all districts can be connected
  for (auto &edge : edges){
    cout << edge[0] << " " << edge[1] << "\n"; // Output each road
  }
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