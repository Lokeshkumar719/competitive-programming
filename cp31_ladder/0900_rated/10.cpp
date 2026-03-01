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
    
    // Your code here
    
    int t;
    cin>>t;

    while(t--){
        int n,q;
        cin>>n>>q;

        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        for(int i=1;i<n;i++){
            v[i]+=v[i-1];
        }

        while(q--){
            int l,r,k;
            cin>>l>>r>>k;

            int newSum=v[n-1];
            // subtract the previous sum
            newSum-=v[r-1];
            newSum-=((l-2)>=0)? v[l-2]:0;
            // add the new sum(k*(r-l+1))
            newSum+=(k*(r-l+1));
            // check if odd or even
            if(newSum&1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}