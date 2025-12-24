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
        int a,b,n;
        cin>>a>>b>>n;

        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int ans=0;
        ans+=(b-1);
        for(int i=0;i<n;i++){
            int incre=min(1+v[i],a);
            if(i!=n-1)ans+=incre-1;
            else ans+=incre;
        }
        cout<<ans<<endl;

    }
    return 0;
}