#include <bits/stdc++.h>
using namespace std;
using ll = __int128;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl "\n"

ll check(long long k){
    return ((ll)k + (ll)(k-1)*(ll)(k)*(ll)(k+1)/(ll)6);
}
// ---------- Write solution here ----------
void solve(){
  long long n;
  cin>>n;
  long long lo = 1; long long hi = 2000000;
  while(lo < hi){
    long long mid = (lo + hi + 1)/2;
    if(check(mid) <= (ll)n){
        lo = mid;
    }else{
        hi = mid-1;
    }
  }
  cout << lo << endl;
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