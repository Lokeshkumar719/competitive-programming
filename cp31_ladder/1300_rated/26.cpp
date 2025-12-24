#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
  string withErr;
  cin>>withErr;
  string withoutErr="";
  int totW=0;
  for(int i=1;i<withErr.size();i++){
    if(withErr[i]=='v' && withErr[i-1]=='v'){
      withoutErr.push_back('w');
      totW++;
    }else if(withErr[i]=='o'){
      withoutErr.push_back('o');
    }
  }
  int ans=0;
  int cntw=0;
  for(int i=0;i<withoutErr.size();i++){
    if(withoutErr[i]=='w'){
      cntw++;
    }else if(withoutErr[i]=='o'){
      ans+=(cntw)*(totW-cntw);
    }
  }
  cout<<ans<<endl;
}
int32_t main() {
    fastio;
    int t=1;
    while(t--) {
      solve();
    }
    return 0;
}