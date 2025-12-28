#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
// ---------- Write solution here ----------
void solve() {
  string r;
  cin>>r;
  int n=r.size();
  int ans=0;
  int left=0;
  if(r[0]=='u') ans++;
  if(r.back()=='u') ans++;
  r[0]='s';
  r.back()='s';
  int len=0;
  for(int i=0;i<n;i++){
    if(r[i]=='u') len++;
    else{
      ans+=(len/2);
      len=0;
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