class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int j = n-1;
        while(j>0 && arr[j] >= arr[j-1])
            j--;

        int ans = j; // most important cann't keep n-1 or INT_MAX as arr[0] can be the maximum elment of the array then ans will never be correct if kept anything other than this because inner loop will never run
        int i = 0;
        while(i<j && (i == 0 || arr[i] >= arr[i-1])){
            while(j<n && arr[i] > arr[j]){
                j++;
            }
            ans = min(ans,j-i-1);
            i++;
        }

        return ans;
    }
};