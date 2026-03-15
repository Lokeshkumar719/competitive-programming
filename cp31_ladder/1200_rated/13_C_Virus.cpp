#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t; // Read the number of test cases
	while (t--) {
		int n, m;
		cin >> n >> m; // Read the number of houses and initially infected houses
		vector<int> v(m);
		for (int i = 0; i < m; i++)
			cin >> v[i]; // Read the indices of initially infected houses
		sort(v.begin(), v.end()); // Sort the infected house indices
		vector<int> gaps;
		for (int i = 0; i < m - 1; i++) {
			gaps.push_back(v[i + 1] - v[i] - 1); // Calculate gaps between consecutive infected houses
		}
		gaps.push_back(v[0] + n - v[m - 1] - 1); // Calculate the gap between the last and first infected house (circular)
		sort(gaps.rbegin(), gaps.rend()); // Sort gaps in descending order
		int numSaved = 0, numDays = 0; // Initialize counters for saved houses and days
		for (auto gap : gaps) {
			int currGap = gap - numDays * 2; // Adjust current gap by the number of days passed
			if (currGap > 0) {
				numSaved++; // Protect the left extremity of the current gap
				currGap -= 2; // Protect the right extremity and all elements in the range
				if (currGap > 0)
					numSaved += currGap;
				numDays += 2; // Increment the number of days
			}
		}
		cout << (n - numSaved) << "\n"; // Output the minimum number of infected houses
	}
	return 0;
}
//! Total Time Complexity (TC): O(m log m)
//! Total Space Complexity (SC): O(m)
