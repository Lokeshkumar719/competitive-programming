#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
  int n,k;
  cin>>n>>k;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  int i=0;
  int j=0;
  double windowSum=0;
  for(j=0;j<k;j++){
    windowSum+=v[j];
  }
  double totalSum=windowSum;
  while(j<n){
    windowSum+=v[j];
    windowSum-=v[i];
    totalSum+=windowSum;
    j++;
    i++;
  }
  double average=(double)totalSum/(n-k+1);
  printf("%.8f",average);
}
int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}