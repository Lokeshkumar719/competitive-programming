class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> vec = nums;
        sort(begin(vec), end(vec));

        int groupNum = 0;
        unordered_map<int, int> numToGroup;
        numToGroup[vec[0]] = groupNum;

        unordered_map<int, queue<int>> groupToList;
        groupToList[groupNum].push(vec[0]);

        for (int i = 1; i < n; i++) {
            if (abs(vec[i] - vec[i - 1]) > limit) {
                groupNum += 1;
            }

            numToGroup[vec[i]] = groupNum;
            groupToList[groupNum].push(vec[i]);
        }

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int group = numToGroup[num];
            // smallest available number in this group
            result[i] =
                groupToList[group].front(); // use hogaya to delete kardo elemen ko
            groupToList[group].pop();
        }

        return result;
    }
};