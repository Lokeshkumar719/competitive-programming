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
        int cnt=0;

        for(int i=0;i<n-1;i++){
            if( ((v[i]&1) && (v[i+1]&1)) ||( (v[i]%2==0) && (v[i+1]%2==0) )) cnt++;
        }

        cout<<cnt<<endl;

    }
    
    return 0;
}