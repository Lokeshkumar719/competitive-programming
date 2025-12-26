#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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

ll sumofAllDivisors(const vector<int>& spf, int n) {
  ll ans = 1;

  while (n != 1) {
    int prime = spf[n];
    ll power = 1, powerSum = 1;

    while (n % prime == 0) {
      n /= prime;
      power *= prime;
      powerSum += power;
    }
    ans *= powerSum;
  }
  return ans;
}

int main() {
  fastio;

  int maxi = 1e6;
  vector<int> spf = buildSieve(maxi);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << sumofAllDivisors(spf, n) << '\n';
  }
  return 0;
}