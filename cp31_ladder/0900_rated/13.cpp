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
        // reach to first non zero element
        int i=0;
        while(i<n && v[i]==0)i++;
        // now count toral subarrays with no 0
        while(i<n){
            // if 0 then move to another subarray starting from non-zero element
            if(v[i]==0){
                cnt++;
                if(cnt>1) break;
                while(i<n && v[i]==0)i++;
            }
            else i++;
        }
        // to cnt last subarray
        if(v[n-1]!=0) cnt++;
        (cnt<=1)? cout<<cnt<<endl:cout<<2<<endl;
    }
    
    return 0;
}