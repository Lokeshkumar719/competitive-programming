class Solution {
public:
    struct Node {
        long long score = -1;
        vector<int> idxs;
    };

    vector<vector<Node>> dp;
    vector<int> nextIdx;x

    int findNextIdx(vector<vector<int>>& intervals, int target) {
        int n = intervals.size();
        int lo = 0, hi = n - 1;
        int ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (intervals[mid][0] > target) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }

    Node getBest(Node take, Node notTake) {
        sort(take.idxs.begin(), take.idxs.end());
        Node result;

        if (take.score > notTake.score) {
            result = take;
        } else if (take.score < notTake.score) {
            result = notTake;
        } else {
            result = (take.idxs < notTake.idxs) ? take : notTake;
        }

        return result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int k = 4;

        for (int i = 0; i < n; i++)
            intervals[i].push_back(i);

        sort(intervals.begin(), intervals.end());

        nextIdx.resize(n, n);
        for (int i = 0; i < n - 1; i++) {
            int endTime = intervals[i][1];
            int idx = findNextIdx(intervals, endTime);
            nextIdx[i] = idx;
        }

        dp.resize(n + 1, vector<Node>(k + 1));

        for (int i = 0; i <= n; i++)
            dp[i][0].score = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 4; k >= 1; k--) {
                // take case
                int score = intervals[i][2];
                int actualIdx = intervals[i][3];
                int j = nextIdx[i];

                Node take = dp[j][k - 1];
                take.idxs.push_back(actualIdx);
                take.score += score;

                // not take case
                Node notTake = dp[i + 1][k];

                // take the best of two 
                Node result = getBest(take, notTake);

                dp[i][k] = result;
            }
        }
        return dp[0][4].idxs;
    }
};