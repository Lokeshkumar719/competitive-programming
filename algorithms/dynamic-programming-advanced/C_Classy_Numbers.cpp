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
ll dp[20][2][4];

ll f(string s,ll idx,ll tight,ll cnt){
  if(idx==s.size()) return cnt<=3;
  if(dp[idx][tight][cnt]!=-1) return dp[idx][tight][cnt];
  ll limit=(tight==1)? s[idx]-'0':9;
  ll ans=0;
  for(ll dig=0;dig<=limit;dig++){
    ll newCnt=cnt+(dig!=0);
    // if call for every new cnt it will cause TLE
    if(newCnt<=3){
      ans+=f(s,idx+1,tight&&(dig==(s[idx]-'0')),(cnt+(dig!=0)));
    }
  }
  return dp[idx][tight][cnt]=ans;
}
// ---------- Write solution here ----------
void solve(){
  ll l,r;
  cin>>l>>r;
  string ub=to_string(r);
  string lb=to_string(l-1);
  memset(dp,-1,sizeof(dp));
  ll rightAns=f(ub,0,1,0);
  memset(dp,-1,sizeof(dp));
  ll leftAns=f(lb,0,1,0);
  cout<<(rightAns-leftAns)<<endl;
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