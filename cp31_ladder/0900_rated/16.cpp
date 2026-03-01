#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int32_t main() {
    fastio
    
    int t;
    cin>>t;

    while(t--){
        string s,t;
        cin>>s>>t;

        map<char,int>mp;
        for(auto &ch:t){
            mp[ch]++;
        }
        
        for(int i=s.size()-1;i>=0;i--){
            if(mp[s[i]]>0){
                mp[s[i]]--;
            } else if(mp[s[i]]==0) s[i]='.';
        }
        string check="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='.') check+=s[i];
        }

        if(check==t) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    
    return 0;
}