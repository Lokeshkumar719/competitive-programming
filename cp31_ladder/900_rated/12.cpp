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
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int ans=v[n-1]-v[0];
        // fixing v[0]
        for(int i=1;i<n;i++){
            ans=max(ans,v[i]-v[0]);
        }
        // fixing v[n-1];
        for(int i=0;i<n-1;i++){
            ans=max(ans,v[n-1]-v[i]);
        }
        // moving both
        for(int i=0;i<n-1;i++){
            ans=max(ans,v[i]-v[i+1]);
        }

        cout<<ans<<endl;
    }
    
    return 0;
}