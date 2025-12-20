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
vector<int> prevSmaller(vector<int>&v){
    int n=v.size();
    vector<int>ans(n);
    ans[0]=-1;
    int idx=0;
    for(int i=1;i<n;i++){
        if(v[idx]<v[i]){
            ans[i]=idx;
        }else{
            ans[i]=-1;
            idx=i;
        }
    }
    return ans;
}
vector<int>nextSmaller(vector<int>&v){
    int n=v.size();
    vector<int>ans(n);
    ans[n-1]=n;
    int idx=n-1;
    for(int i=n-1;i>=0;i--){
        if(v[idx]<v[i]){
            ans[i]=idx;
        }else{
            ans[i]=n;
            idx=i;
        }
    }
    return ans;
}
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

        // vector<int>prev=prevSmaller(v);
        // vector<int>next=nextSmaller(v);
        // bool check=0;
        // for(int i=1;i<n-1;i++){
        //     if(prev[i]!=-1 && next[i]!=n){
        //         cout<<"YES"<<endl;
        //         cout<<prev[i]+1<<" "<<i+1<<" "<<next[i]+1<<endl;
        //         check=1;
        //         break;
        //     }
        // }
        // if(!check) cout<<"NO"<<endl;

        bool check=0;
        for(int i=1;i<n-1;i++){
            if(v[i]>v[i-1] && v[i]>v[i+1]){
                cout<<"YES"<<endl;
                cout<<i<<" "<<i+1<<" "<<i+2<<endl;
                check=1;
                break;  
            }
        }

        if(!check) cout<<"NO"<<endl;



    }
    
    return 0;
}