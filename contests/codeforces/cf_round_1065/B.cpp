#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    if(v[0]==-1 || v[n-1]==-1){
        cout<<0<<endl;
    }else{
        cout<<abs(v[n-1]-v[0])<<endl;
    }
    if(v[0]==-1 && v[n-1]==-1){
        v[0]=0;
        v[n-1]=0;
    }else if(v[0]==-1 && v[n-1]!=-1){
        v[0]=v[n-1];
    }else if(v[0]!=-1 && v[n-1]==-1){
        v[n-1]=v[0];
    }

    for(int i=1;i<n-1;i++){
        if(v[i]==-1) v[i]=0;
    }
    for(auto &ele:v){
        cout<<ele<<" ";
    }
    cout<<endl;
}
int32_t main() {
    fastio;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}