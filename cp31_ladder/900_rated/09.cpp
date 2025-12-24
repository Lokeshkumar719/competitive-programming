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
#include<numeric>

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
        
        int ans=0;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];  
            ans=gcd(ans,abs(v[i]-(i+1)));
        }

        cout<<ans<<endl;
    }
    
    return 0;
}