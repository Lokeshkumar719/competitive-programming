#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

// ---------- Write solution here ----------
void solve() {
  ll n;
  cin>>n;

  if(n&1){
    cout<<0<<endl;
    return;
  }

  if((n/10==0) && !(n&1)){
    cout<<-1<<endl;
    return;
  }

  // case in which we already have a odd digit
  string s=to_string(n);
  bool isOdd=false;
  for(int i=0;i<s.size();i++){
    if((s[i]-'0')&1){
      isOdd=true;
    }
  }
  if(isOdd){
    cout<<1<<endl;
    return;
  }

  // case when all digit are even
  sort(s.begin(),s.end());
  
  // check if after substracting maximum digit we got a number in which atleast one digit is odd (if yes then anser is 2 else 3)
  int dig=s[s.size()-1]-'0';
  if((n-dig)%10!=0){
    cout<<2<<endl;
    return;
  }else{
    cout<<3<<endl;
  }

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