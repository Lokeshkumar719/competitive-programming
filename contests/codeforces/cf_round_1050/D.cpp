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
        vector<int>odd;
        int evenSum=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]&1){
                odd.push_back(v[i]);
            }else{
                evenSum+=v[i];
            }
        }
        if(odd.size()==0){
            cout<<0<<endl;
            continue;
        }

        sort(odd.begin(),odd.end());

        int x=odd.size();
        int y=(x+1)/2;
        for(int i=x-y;i<x;i++){
            evenSum+=odd[i];
        }

        cout<<evenSum<<endl;

    }
    
    return 0;
}