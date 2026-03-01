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
        int mini=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(v[i]>v[maxi]) maxi=i;
            if(v[i]<v[mini]) mini=i;
        }

        if(v[maxi]==v[mini]) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            cout<<v[maxi]<<" "<<v[mini]<<" ";
            for(int i=0;i<n;i++){
                if(i==mini || i==maxi) continue;
                else cout<<v[i]<<" ";
            }
            cout<<endl;
        }
    }
    
    return 0;
}