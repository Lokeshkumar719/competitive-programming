class Solution {
	public:
	int minSteps(vector<int>& arr, int start, int end) {
		int n = arr.size();
		if(start == end)
		    return 0;
		const int MOD = 1000;
		vector<bool> vis(MOD, false);
		queue<int>q;
		q.push(start);
		vis[start] = true;
		int cnt = 0;
		while (!q.empty()) {
			int x = q.size();
			for (int i = 1; i <= x; i++) {
				int node = q.front();
				q.pop();
				for (auto &ele:arr) {
					int res = (node*ele)%MOD;
					if (res == end)
						return cnt + 1;
					if (!vis[res]) {
						q.push(res);
						vis[res] = true;
					}
				}
			}
			cnt++;
		}
		return -1;
	}
};