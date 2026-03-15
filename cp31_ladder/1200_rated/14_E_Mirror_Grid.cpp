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
  int n;
  cin >> n; // Read the size of the grid for each test case
  // Initialize the grid with n x n dimensions
  vector<vector<char>> mat(n, vector<char>(n));
  // Read the grid values
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++)
      cin >> mat[i][j];
  } // O(n^2) to read the grid
  int ans = 0; // Initialize the answer for the minimum number of operations
  // Iterate over each cell in the grid
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      int c0 = 0, c1 = 0; // Counters for 0s and 1s
      // Check the current cell and its three symmetric counterparts
      if(mat[i][j] == '0')
        c0++;
      else
        c1++;

      if(mat[j][n - i - 1] == '0')
        c0++;
      else
        c1++;

      if(mat[n - i - 1][n - j - 1] == '0')
        c0++;
      else
        c1++;

      if(mat[n - j - 1][i] == '0')
        c0++;
      else
        c1++;

      // If all are 0s or all are 1s, no operation is needed
      if((c0 == 0) or (c1 == 0))
        continue;
      // If 1s are in minority, change all 1s to 0s
      if(c0 >= c1){
        ans += c1;
        mat[i][j] = '0';
        mat[j][n - i - 1] = '0';
        mat[n - i - 1][n - j - 1] = '0';
        mat[n - j - 1][i] = '0';
      }
      else{
        // If 0s are in minority, change all 0s to 1s
        ans += c0;
        mat[i][j] = '1';
        mat[j][n - i - 1] = '1';
        mat[n - i - 1][n - j - 1] = '1';
        mat[n - j - 1][i] = '1';
      }
    }
  }
  // Output the minimum number of operations for the current test case
  cout << ans << "\n";
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