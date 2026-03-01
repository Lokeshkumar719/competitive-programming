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
        int n,k;
        cin>>n>>k;

        vector<int>v(n*k);
        for(int i=0;i<n*k;i++){
            cin>>v[i];
        }
        int pointer=n*k;
        int ans=0;
        while(k--){
            pointer-=(n/2+1);
            ans+=v[pointer];
        }

        cout<<ans<<endl;
    }
    
    return 0;
}