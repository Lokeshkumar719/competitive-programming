#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// PROBLEM-1:
// Approach:sort the array then select two indices and then two pointer on rest of array
void solve() {
    int n,x;
    cin>>n>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        mp[v[i]].push_back(i);
    }
    sort(v.begin(),v.end());
    int ele1=-1,ele2=-1,ele3=-1,ele4=-1;
    bool check=false;
    for(int i=0;i<n;i++){
        while(i>0 && v[i-1]==v[i]) continue;
        for(int j=i+1;j<n;j++){
            while(v[j-1]==v[j]) continue;
            int reqdSum=x-v[i]-v[j];
            int k=j+1;
            int l=n-1;
            while(k<l){
                if(v[k]+v[l]==reqdSum){
                    ele1=v[i];ele2=v[j];ele3=v[k];ele4=v[l];
                    check=true;
                    break;
                }else if(v[k]+v[l]<reqdSum){
                    k++;
                }else l--;
            }
            if(check)break;
        }
        if(check)break;
    }

    if(check){
        int i1=mp[ele1].back()+1;mp[ele1].pop_back();
        int i2=mp[ele2].back()+1;mp[ele2].pop_back();
        int i3=mp[ele3].back()+1;mp[ele3].pop_back();
        int i4=mp[ele4].back()+1;mp[ele4].pop_back();
        vector<int>idx={i1,i2,i3,i4};
        sort(idx.begin(),idx.end());
        for(auto &ele:idx){
            cout<<ele<<" ";
        }  
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}
// T.C=O(N^3)
// S.C=O(N)
int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}