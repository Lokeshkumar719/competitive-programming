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
        map<int,int>mp;
        int maxi=0;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            mp[v[i]]++;
            maxi=max(maxi,mp[v[i]]);
        }

        int x=maxi;
        int copy=0;
        while(x<n){
            x*=2;
            copy++;
        }

        int ans=copy;
        for(int i=1;i<copy;i++){
            ans+=maxi;
            maxi*=2;
        }

        ans+=n-maxi;

        cout<<ans<<endl;


    }
    
    return 0;
}