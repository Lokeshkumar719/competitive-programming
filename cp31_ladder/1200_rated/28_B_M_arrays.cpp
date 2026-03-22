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
  int n, m;
  cin >> n >> m; // Read n (number of elements) and m (divisor)
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i]; // Read the array elements
  vector<int> rem(m); // Initialize a vector to count remainders
  // Count the frequency of each remainder when elements are divided by m
  for (int i = 0; i < n; i++) {
    rem[v[i] % m]++;
  }
  int ans = 0; // Initialize the answer to store the number of m-divisible arrays
  // Iterate over each possible remainder
  for (int i = 0; i < m; i++) {
    int x = rem[i], y = rem[(m - i) % m];
    // If both remainders are zero, continue to the next
    if ((x == 0) and (y == 0))
      continue;
    // Calculate the minimum of the two counts
    int tmp = min(x, y);
    // Adjust the counts by removing pairs
    x -= min(tmp + 1, x);
    y -= min(tmp + 1, y);
    // Increment the answer for each pair
    ans++;
    // Add the remaining elements to the answer
    ans += (x + y);
    // Reset the counts for these remainders
    rem[i] = 0;
    rem[(m - i) % m] = 0;
  }
  cout << ans << "\n"; // Output the result for the current test case
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