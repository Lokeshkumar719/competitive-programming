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

        int ans=0;

        if(n>=1 && n<10){
            ans+=n;
        }
        if(n>=10 && n<100){
            ans+=9;
            ans+=n/10;
        }
        if(n>=100 && n<1000){
            ans+=18;
            ans+=n/1e2;
        }
        if(n>=1e3 && n<1e4){
            ans+=(27);
            ans+=n/1e3;
        }
        if(n>=1e4 && n<1e5){
            ans+=(27+9);
            ans+=n/1e4;
        }
        if(n>=1e5 && n<1e6){
            ans+=(27+9+9);
            ans+=n/1e5;
        }

        cout<<ans<<endl;
        
    }
    
    return 0;
}