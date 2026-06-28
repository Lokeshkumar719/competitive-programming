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
const ll mod=(ll)1e9+7;

int dp[10005][2][105];
// ---------- Write solution here ----------
ll solve(string s,int idx,int tight,int sum,int d){
  if(idx==(int)s.size()) return (ll)(sum==0);
  if(dp[idx][tight][sum]!=-1) return dp[idx][tight][sum];
  int limit=(tight)? s[idx]-'0':9;
  ll ans=0;
  for(int dig=0;dig<=limit;dig++){
    ans=(ans+solve(s,idx+1,(tight && (dig == s[idx]-'0')),(sum+dig)%d,d))%mod;
  }
  return dp[idx][tight][sum]=ans;
}

// ---------- Main ----------
int main(){
  fastio;
  string k;int d;
  cin>>k>>d;
  memset(dp,-1,sizeof(dp));
  // -1 due to 0
  cout<<(solve(k,0,1,0,d)-1+mod)%mod;
  return 0;
}