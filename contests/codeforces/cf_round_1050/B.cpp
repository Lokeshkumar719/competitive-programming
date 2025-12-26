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
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        vector<int>v1(n);
        for(int i=0;i<n;i++){
            cin>>v1[i];
        }
        vector<int>v2(m);
        for(int i=0;i<m;i++){
            cin>>v2[i];
        }

        cout<<n+m<<endl;
    }
    
    return 0;
}