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

// Helper functions
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int power(int a, int b, int mod) {
    int res = 1;
    a %= mod;
    while(b > 0) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
bool isPrime(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 5; i*i <= n; i += 6)
        if(n % i == 0 || n % (i+2) == 0) return false;
    return true;
}

int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int ans=1;
        for(int i=0;i<n;i++){
            if(v[i]>ans){
                break;
            }
            ans+=(v[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}