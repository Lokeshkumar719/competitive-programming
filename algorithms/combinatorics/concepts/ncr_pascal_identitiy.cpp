#include <bits/stdc++.h>
using namespace std;

// pascal's identity
// (n/r)=(n-1/r-1)+(n-1/r)

long long nCr(int n, int r) {
    vector<vector<long long>> dp(n + 1, vector<long long>(r + 1, 0));
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= min(i, r); j++) {
        if (j == 0 || j == i)
          dp[i][j] = 1;
        else
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      }
    }
    return dp[n][r];
}

int main() {
    cout << nCr(31, 15) << endl;
    return 0;
}