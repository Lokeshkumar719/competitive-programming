class Solution {
public:
    string getMinLengthBeautifulString(string& s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        int cnt = 0;
        string result = "";
        while (j < n) {
            cnt += (s[j] == '1');

            while (cnt == k) {
                string sub = s.substr(i, j - i + 1);
                if (result.empty() || sub.length() < result.length() ||
                    (result > sub && result.length() == sub.size())) {
                    result = sub;
                }
                cnt -= (s[i++] == '1');
            }

            j++;
        }

        return result;
    }
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        return getMinLengthBeautifulString(s, k);
    }
};