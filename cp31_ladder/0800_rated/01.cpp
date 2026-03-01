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
    // taking input
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        // vector to store elements
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        // check if already sorted
        bool isSorted=true;
        for(int i=0;i<n-1;i++){
            if(v[i]>v[i+1]){
                isSorted=false;
                break;
            }
        }
        if(isSorted) cout<<"YES"<<endl;
        else{
            if(k==1) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    } 
    return 0;
}