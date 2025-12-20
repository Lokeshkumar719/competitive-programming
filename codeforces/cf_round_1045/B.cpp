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
        int n,k;
        cin>>n>>k;

        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        if(k&1){
            for(int i=0;i<n;i++){
                if(v[i]&1){
                    v[i]+=k;
                }
            }
        } else{
            for(int i=0;i<n;i++){
                while((v[i]%3)!=0){
                    v[i]+=k;
                }
            }
        }

        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    
    }
    
    return 0;
}