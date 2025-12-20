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
// using a queue to so that we can push the elements which are required to be ignored in an iteration at back so that they can be proccesed later
void solve() {
    int n;
    cin>>n;
    queue<int>q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    bool pick=false;
    while(!q.empty()){
        int ele=q.front();
        q.pop();
        if(pick){
            cout<<ele<<" ";
        }else{
            q.push(ele);
        }
        pick=(!(pick));
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