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
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
bool isPrime(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 5; i*i <= n; i += 6)
        if(n % i == 0 || n % (i+2) == 0) return false;
    return true;
}

//using a standard expansion and contraction sliding window approach and a set to ensure only unique elements are there in considered window.
void solve() {
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int l=0,r=0;
    int maxlen=INT_MIN;
    set<int>s;
    while(r<n){
        if(s.count(v[r])){
            while(s.count(v[r])){
                s.erase(v[l]);
                l++;
            }
        }
        s.insert(v[r]);
        maxlen=max(maxlen,r-l+1);
        r++;   
    }
    cout<<maxlen<<endl;
}
//T.C=O(NlogN);
// S.C=O(N);

int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}