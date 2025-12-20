#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <climits>
#include <bitset>
#include <cassert>
#include <iomanip>
#include <functional>
using namespace std;
#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
void solve() {
    int n,x;
    cin>>n>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    map<int,int>mp;
    mp[0]=1;
    int sum=0;
    int ans=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
        int reqd=sum-x;
        if(mp.find(reqd)!=mp.end()){
            ans+=mp[reqd];
        }
        mp[sum]++;
    }
    cout<<ans<<endl;

}
int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}