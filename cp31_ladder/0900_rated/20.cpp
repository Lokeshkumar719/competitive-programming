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

int32_t main(){

    fastio
    
    int t;
    cin>>t;


    while(t--){
        string s;
        cin>>s;

        if(s[0]==s.back()){
            cout<<s<<endl;
            continue;
        }

        if(s[0]=='a') s[0]='b';
        else s[0]='a';

        cout<<s<<endl;

        
    }
    return 0;

}