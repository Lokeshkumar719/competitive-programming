#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void solve() {
    int x,n;
    cin>>x>>n;
    set<int>ligths;
    ligths.insert(0);
    ligths.insert(x);
    multiset<int>segments;
    segments.insert(x);
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(auto pos:v){
        auto it=ligths.upper_bound(pos);
        int right=*(it);
        int left=*(prev(it));
        ligths.insert(pos);

        segments.erase(segments.find(right-left));

        segments.insert(pos-left);
        segments.insert(right-pos);

        cout<<*(segments.rbegin())<<" ";
    }

    cout<<endl;
}
int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}