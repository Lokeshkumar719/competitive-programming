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

// creating a vector towers(stores towers bases) finding if ceil(base greater than that element) is present using binary search of towers array if ceil is found then update base if not push the base as it will form new tower
int getCeil(int tar,vector<int>&towers){
    int lo=0;
    int hi=towers.size()-1;
    int ceil=towers.size();
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(towers[mid]>tar){
            ceil=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    return ceil;
}
void solve() {
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>towers;
    towers.push_back(v[0]);
    for(int i=1;i<n;i++){
        int ceil=getCeil(v[i],towers);
        if(ceil==towers.size()){
            towers.push_back(v[i]);
        }else{
            towers[ceil]=v[i];
        }
    }
    cout<<towers.size()<<endl;
}
// T.C=O(nlogn)
// S.C=O(n)

int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}