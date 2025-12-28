#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

// ---------- Write solution here ----------
void solve() {
  string s;
  cin>>s;
  int cntY=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='Y') cntY++;
  }
  cout<< ((cntY>1)? "NO": "YES") <<endl;
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