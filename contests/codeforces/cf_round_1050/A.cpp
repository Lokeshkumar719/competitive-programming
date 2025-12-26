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
        int x,n;
        cin>>x>>n;
        if(n&1){
            cout<<x<<endl;
        }else cout<<0<<endl;
    }
    
    return 0;
}