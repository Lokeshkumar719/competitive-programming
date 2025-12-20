#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// Approach:we should minimise the finishing time as deadline is fixed(or we can say sum of deadlines is fixed so need to minimise the finishing time of each task), so sort according to duration
void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
        int d,f;
        cin>>d>>f;
        v[i]={d,f};
    }
    sort(v.begin(),v.end());
    int ans=0;
    int finishTime=0;
    for(int i=0;i<n;i++){
        finishTime+=v[i].first;
        int deadline=v[i].second;
        ans+=deadline-finishTime;
    }
    cout<<ans<<endl;
}
// T.C=O(nlogn);
// S.C=O(logn);

int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}