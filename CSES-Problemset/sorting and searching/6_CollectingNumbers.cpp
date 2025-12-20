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
// APPROACH: maintaining the last element of previous round and the element we need w=and whenver the required condition is not satisfied we increase number of rounds
void solve() {
    int n;
    cin >> n;
    // cleaner approach:
    // If number x is before number x-1 in the array, we have to start a new round after collecting number x-1.
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
    }

    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i - 1]) rounds++;
    }
    cout << rounds << "\n";
}

int32_t main() {
    fastio;
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}