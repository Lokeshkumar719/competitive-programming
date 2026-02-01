class Solution {
public:
  int minLength(vector<int>& nums, int k) {
    int n=nums.size();
    int sum=0;
    int ans=n+1;
    int i=0,j=0;
    map<int,int>mp;
    while(j<n){
        mp[nums[j]]++;
        if(mp[nums[j]]==1) sum+=nums[j];
        while(sum>=k){
          ans=min(ans,j-i+1);
          mp[nums[i]]--;
          if(mp[nums[i]]==0) sum-=nums[i];
          i++;
        }
        j++;
    }
    return (ans!=(n+1))? ans:-1;
  }
};