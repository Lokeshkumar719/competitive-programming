class Solution {
using ll=long long;
public:
  long long gcdSum(vector<int>& nums) {
    int n=nums.size();
    vector<int>prefixGcd(n);
    int gcd=nums[0];
    int maxi=nums[0];
    prefixGcd[0]=nums[0];
    for(int i=1;i<n;i++){
      maxi=max(maxi,nums[i]);
      prefixGcd[i]=(int)__gcd(nums[i],maxi);
    }
    sort(prefixGcd.begin(),prefixGcd.end());
    int i=0,j=n-1;
    ll sum=0LL;
    while(i<j){
      sum+=(ll)(__gcd(prefixGcd[i],prefixGcd[j]));
      i++;
      j--;
    }
    return sum;
  }
};