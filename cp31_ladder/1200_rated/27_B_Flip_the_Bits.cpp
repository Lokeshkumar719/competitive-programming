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
  cin >> n; // Read the length of strings a and b
  string a,b;
  cin >>a>>b; // Read strings a and b
  // Vector to keep track of positions where we can flip
  vector<bool> canFlip(n);
  int count0 = 0, count1 = 0; // Counters for 0s and 1s
  for (int i = 0; i < n; i++) {
    if (a[i] == '0') {
      count0++; // Increment count0 if current character is '0'
    } else {
      count1++; // Increment count1 if current character is '1'
    }
    // Mark position as flippable if counts of 0s and 1s are equal
    if (count0 == count1) canFlip[i] = true;
  } //? O(N)
  bool isFlipped = false; // Track if the current state is flipped
  bool isPoss = true; // Track if transformation is possible
  // Traverse the strings from the end to the beginning
  for (int i = n - 1; i >= 0; i--) {
    if (isFlipped == false) {
      // If not flipped, check if characters are different
      if (a[i] != b[i]) {
        if (canFlip[i]) {
          isFlipped ^= true; // Flip the state
        } else {
          isPoss = false; // Transformation not possible
          break;
        }
      }
    } else {
      // If flipped, check if characters are the same
      if (a[i] == b[i]) {
        if (canFlip[i]) {
          isFlipped ^= true; // Flip the state
        } else {
          isPoss = false; // Transformation not possible
          break;
        }
      }
    }
  } //? O(N)
  // Output the result for the current test case
  if (isPoss) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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