class Solution {
  public:
    string findOrder(vector<string> &words) {
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);

        // Mark characters present
        for (auto &word : words) {
            for (char ch : word) {
                present[ch - 'a'] = true;
            }
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';

                    adj[u].push_back(v);
                    indegree[v]++;
                    found = true;
                    break;
                }
            }

            // Invalid case: prefix problem
            if (!found && s1.size() > s2.size()) {
                return "";
            }
        }

        // Topological sort (Kahn's Algorithm)
        queue<int> q;

        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        string ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans += char(node + 'a');

            for (auto neigh : adj[node]) {
                indegree[neigh]--;

                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        // Cycle detection
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (present[i])
                count++;
        }

        if (ans.size() != count)
            return "";

        return ans;
        
    }
};