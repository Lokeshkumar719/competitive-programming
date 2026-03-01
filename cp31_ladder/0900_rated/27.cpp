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
        int n,x;
        cin>>n>>x;

        vector<int>v(n);
        int sum=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            maxi+=(int)ceil((double)v[i]/x);
            sum+=(v[i]);
        }
        int mini=(int)ceil(sum/(double)x);
        cout<<mini<<" "<<maxi<<endl;    
    }

    return 0;
}