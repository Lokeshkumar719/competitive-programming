#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  set<string> st;
  for(int i=0;i<n;i++)st.insert(s.substr(i,1));
  for(int i=0;i+1<n;i++)st.insert(s.substr(i,2));
  for(int i=0;i+2<n;i++)st.insert(s.substr(i,3));
  // check for 1 length
  for(char a='a';a<='z';a++){
    string t="";
    t+=a;
    if(!st.count(t)){
      cout<<t<<endl;
      return;
    }
  }
  // 2 length
  for(char a='a';a<='z';a++){
    for(char b='a';b<='z';b++){
      string t="";
      t+=a;
      t+=b;
      if(!st.count(t)){
        cout<<t<<endl;
        return;
      }
    }
  }
  // 3 length
  for(char a='a';a<='z';a++){
    for(char b='a';b<='z';b++){
      for(char c='a';c<='z';c++){
        string t="";
        t+=a;
        t+=b;
        t+=c;
        if(!st.count(t)){
          cout<<t<<endl;
          return;
        }
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin>>t;
  while(t--){
    solve();
  }
}