#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

int fact[5]={1,1,2,6,24};

ll dearrangement(int k){
  if(k==2) return 1;
  if(k==3) return 2;
  if(k==4) return 9;
}

ll ncr(int n,int k){
  ll ans=1;
  for(ll num=(n-k+1);num<=n;num++){
    ans*=num;
  }
  ans/=fact[k];
  return ans;
}

int main() {
  fastio;

  ll n,k;
  cin>>n>>k;
  ll ans=0;
  for(int i=2;i<=k;i++){
    ans+=(ncr(n,i)*(dearrangement(i)));
  }
  ans+=1;
  cout<<ans<<endl;

  return 0;
}