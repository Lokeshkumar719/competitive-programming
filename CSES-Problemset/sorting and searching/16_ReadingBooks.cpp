#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// Approach: answer is either twice the largest time required to read a book(other person can read all other book if largest time>sum of all other times) or the sum of all time.
void solve() {
    int n;
    cin>>n;
    vector<int>v(n);
    int sum=0;
    int maxi=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
        maxi=max(maxi,v[i]);
    }
    cout<<max(2*maxi,sum)<<endl;
}
// T.C=O(1);
// S.C=O(1);
int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}