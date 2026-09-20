#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

vector<int> buildSieve(int maxi) {
  vector<int> spf(maxi + 1);
  for (int i = 1; i <= maxi; i++) spf[i] = i;
  for (int i = 2; i * i <= maxi; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j <= maxi; j += i) {
        if (spf[j] == j)
        spf[j] = i;
      }
    }
  }
  return spf;
}

int numberOfDivisors(const vector<int>& spf, int n) {
  int ans = 1;
  while (n != 1) {
    int prime = spf[n];
    int cnt = 0;
    while (n % prime == 0) {
      n /= prime;
      cnt++;
    }
    ans *= (cnt + 1);
  }
  return ans;
}

int main() {
  fastio;

  int MAXN = 1e6;
  vector<int> spf = buildSieve(MAXN);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << numberOfDivisors(spf, n)-n << '\n';
  }
  
  return 0;
}