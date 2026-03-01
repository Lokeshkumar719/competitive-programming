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
        string s;
        cin>>s;

        int num1=0;
        int num0=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')num0++;
            else if(s[i]=='1') num1++;
        }
        int pairs=min(num0,num1);

        if(pairs&1) cout<<"DA"<<endl;
        else cout<<"NET"<<endl;
    }
    
    return 0;
}