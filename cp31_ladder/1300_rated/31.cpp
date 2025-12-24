#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
bool isPrime(int n) {
  if(n <= 1) return false;
  if(n <= 3) return true;
  if(n % 2 == 0 || n % 3 == 0) return false;
  for(int i = 5; i*i <= n; i += 6)
    if(n % i == 0 || n % (i+2) == 0) return false;
  return true;
}
void solve() {
  string s;
  cin>>s;
  for(int i=1;i<s.size();i++){
    if(s[i]==s[i-1]){
      if(i+1<s.size()){
        char ch=s[i+1];
        for(char ch='a';ch<='z';ch++){
          if(ch!=s[i+1] && ch!=s[i]){
            s[i]=ch;
            break;
          }
        }
      }else{
        if(s[i]=='z'){
          s[i]='a';
        }else s[i]='z';
      }
    }
  }
  cout<<s<<endl;
}
int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}