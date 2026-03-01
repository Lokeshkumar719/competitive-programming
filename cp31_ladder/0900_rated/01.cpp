#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

#define int long long
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int32_t main() {
    fastio;
    
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;
        
        int xk, yk;
        cin >> xk >> yk;

        int xq, yq;
        cin >> xq >> yq;

        int dirc[8][2] = {{-a, b}, {a, b}, {-b, a}, {b, a}, {a, -b}, {-a, -b}, {-b, -a}, {b, -a}};

        set<pair<int,int>> s;
        for (int d = 0; d < 8; d++) {
            int ni = xk + dirc[d][0];
            int nj = yk + dirc[d][1];
            s.insert({ni, nj});
        }

        int ans = 0;
        for (int d = 0; d < 8; d++) {
            int ni = xq + dirc[d][0];
            int nj = yq + dirc[d][1];
            if (s.find({ni, nj}) != s.end()){
                ans++;
                // erase to avoid duplicate ++ as a can be equal to b
                s.erase({ni,nj});
            }
        }

        cout << ans << endl;
    }
    return 0;
}