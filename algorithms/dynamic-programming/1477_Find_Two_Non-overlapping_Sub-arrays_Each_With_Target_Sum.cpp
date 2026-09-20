class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> minLenTillIdx(n, INT_MAX);
        int i = 0, j = 0;
        int sum = 0;
        int ans = INT_MAX;
        int bestMin = INT_MAX;
        while (j < n) {
            sum += arr[j];
            while (sum > target) {
                sum -= arr[i++];
            }
            if (sum == target) {
                int len = j - i + 1;
                bestMin = min(bestMin, len);
                if (i > 0 && minLenTillIdx[i - 1] != INT_MAX) {
                    ans = min(ans, len + minLenTillIdx[i - 1]);
                }
            }
            minLenTillIdx[j] = bestMin;
            j++;
        }

        return (ans != INT_MAX)? ans : -1;
    }
};