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
        int n;
        cin>>n;

        vector<int>v(n);
        map<int,int>mp;
        bool check=false;
        for(int i=0;i<n;i++){
            cin>>v[i];
            mp[v[i]]++;
            if(mp[v[i]]>1){
                check=true;
            }
        }

        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
 
    }
    
    return 0;
}