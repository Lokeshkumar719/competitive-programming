class Solution {
  public:
    int lis(vector<int>& arr) {
       int n=arr.size();
       vector<int>dp;
       dp.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i]>dp.back()){
                dp.push_back(arr[i]);
            }else{
                int low = lower_bound(begin(dp),end(dp),arr[i])-dp.begin();
                dp[low] = arr[i];
            }
        }
        return dp.size();
    }
};