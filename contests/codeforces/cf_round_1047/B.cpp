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
        if(n==2){
            for(int i=0;i<n;i++){
                cin>>v[i];
                cout<<3-v[i]<<" ";
            }
            cout<<endl;
        }else{
            for(int i=0;i<n;i++){
                cin>>v[i];
                if(v[i]==n){
                    cout<<n<<" ";
                }else{
                    cout<<n-v[i]<<" ";
                }
            }
            cout<<endl;
        }
        
    }
    return 0;
}