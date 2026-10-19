class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> ans;

        for (auto& curr : intervals) {

            // Current interval comes before new interval
            if (curr[1] < newInterval[0]) {
                ans.push_back(curr);
            }

            // New interval comes before current interval
            else if (newInterval[1] < curr[0]) {
                ans.push_back(newInterval);
                newInterval = curr;
            }

            // Overlap
            else {
                newInterval[0] = min(newInterval[0], curr[0]);
                newInterval[1] = max(newInterval[1], curr[1]);
            }
        }

        ans.push_back(newInterval);

        return ans;
    }
};