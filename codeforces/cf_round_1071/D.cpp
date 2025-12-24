#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
  int n;
  cin>>n;
  cout<<n<<" "<<n-1<<" ";
  for(int i=1;i<n-1;i++){
    cout<<i<<" ";
  }
  cout<<endl;
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