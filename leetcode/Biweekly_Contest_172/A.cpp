class Solution {
public:
    int minOperations(vector<int>& nums) {
      int n=nums.size();
      unordered_set<int>s;
      int i=n-1;
      while(i>=0){
          if(s.count(nums[i])){
              break;
          }
          s.insert(nums[i]);
          i--;
      }
      int needToRemove=i+1;
      // number of operation will be ceil of (elements to remove)/3
      return (needToRemove+2)/3;
    }
};