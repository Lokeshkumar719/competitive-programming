class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int n=tasks.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int t1=tasks[i][0]+tasks[i][1];
            ans=min(t1,ans);
        }
        return ans;
    }
};