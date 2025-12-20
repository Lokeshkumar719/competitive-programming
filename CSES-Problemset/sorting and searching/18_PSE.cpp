#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// PROBLEM-1
// Approach: standard stack approach to find previous smaller elments's index
void solve() {
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    stack<int>st;
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && v[st.top()]>=v[i]) st.pop();
        ans[i]=(st.empty())? -1:st.top();
        st.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]+1<<" ";
    }
    cout<<endl;
}
// T.C=O(N);
// S.C=O(N);
int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}