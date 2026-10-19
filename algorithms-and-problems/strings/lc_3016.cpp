class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> mp(26);
        for (auto& c : word)
            mp[c - 'a']++;

        sort(rbegin(mp), rend(mp));

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += (i / 8 + 1) * (mp[i]);
        }
        
        return ans;
    }
};