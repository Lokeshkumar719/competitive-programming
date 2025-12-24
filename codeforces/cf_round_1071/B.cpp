#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
bool isPrime(int n) {
  if(n <= 1) return false;
  if(n <= 3) return true;
  if(n % 2 == 0 || n % 3 == 0) return false;
  for(int i = 5; i*i <= n; i += 6)
      if(n % i == 0 || n % (i+2) == 0) return false;
  return true;
}
void solve() {
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++) cin>>v[i];

  int idx=0;
  int diff=abs(v[1]-v[0]);
  for(int i=1;i<n-1;i++){
    int x=abs(abs(v[i]-v[i-1])+abs(v[i]-v[i+1])-abs(v[i-1]-v[i+1]));
    if(x>diff){
      idx=i;
      diff=x;
    }
  }
  int x=abs(v[n-1]-v[n-2]);
  if(x>diff){
    idx=n-1;
    diff=x;
  }

  vector<int>v2;
  for(int i=0;i<n;i++){
    if(i!=idx){
      v2.push_back(v[i]);
    }
  }
  int sum=0;
  for(int i=0;i<v2.size()-1;i++){
    sum+=abs(v2[i]-v2[i+1]);
  }
  cout<<sum<<endl;
}
int32_t main() {
  fastio;
  int t;
  cin >> t;
  while(t--) {
      solve();
  }
  return 0;
}