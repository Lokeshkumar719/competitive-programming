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
int getDigit(int n){
    int start=1;
    int end=9;
    int numLength=1;
    while(n>end*numLength){
        n-=end*numLength;
        start*=10;
        end*=10;
        numLength++;
    }
    int digitSkipped=n-1;
    int numberSkipped=digitSkipped/numLength;

    int exactNumber=start+numberSkipped;
    string s=to_string(exactNumber);
    return s[(n-1)%numLength]-'0';
}
void solve() {
    int q;
    cin>>q;

    while(q--){
        int k;
        cin>>k;

        int ans=getDigit(k);
        cout<<ans<<endl;
    }
}
int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}