#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// Approach:we know that maximum time it can take is minimum element in given array*number of products
// so we get the range of ans.Then applying the binary search on this range to calulate minimum time;
long long numProducts(vector<long long>&v,long long t){
    long long productProduced=0;
    for(auto &el:v){
        productProduced+=(long long)(t/el);
    }
    return productProduced;
}

void solve() {
    long long n,t;
    cin>>n>>t;
    vector<long long>v(n);
    long long mini=LLONG_MAX;
    for(int i=0;i<n;i++){
        cin>>v[i];
        mini=min(mini,v[i]);
    }
    long long lo=1;
    long long hi=mini*t;
    long long ans=hi;
    while(lo<=hi){
        long long mid=lo+(hi-lo)/2;
        if(numProducts(v,mid)>=t){
            ans=mid;
            hi=mid-1;
        }else lo=mid+1;
    }
    cout<<ans<<endl;
}
// T.C=O(n.log(mini*t));
// SC=O(1);
int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}
