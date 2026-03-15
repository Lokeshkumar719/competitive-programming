class Solution {
public:
  int longestArithmetic(vector<int>& nums) {
    int n=nums.size();
    vector<int>left(n,2);
    vector<int>right(n,2);
    for(int i=2;i<n;i++){
      if(nums[i-2]-nums[i-1] == nums[i-1]-nums[i]){
        left[i]=1+left[i-1];
      }
    }
    for(int i=n-3;i>=0;i--){
      if(nums[i]-nums[i+1] == nums[i+1]-nums[i+2]){
        right[i]=1+right[i+1];
      }
    }
    int ans=2;
    for(int i=0;i<n;i++){
        ans=max(ans,max(left[i],right[i]));
        if(i==0){
          ans=max(ans,1+right[i+1]);
        }else if(i==n-1){
          ans=max(ans,1+left[i-1]);
        }else{
            ans=max(ans,1+left[i-1]);
            ans=max(ans,1+right[i+1]);
            // check if mean of left and right work
            if(((nums[i-1]-nums[i+1])%2)==0){
              int reqd=(nums[i-1]-nums[i+1])/2;
              int leftLen=1,rightLen=1;
              if(i>=2 && nums[i-2]-nums[i-1]==reqd){
                leftLen=left[i-1];
              }
              if(i<n-2 &&nums[i+1]-nums[i+2]==reqd){
                rightLen=right[i+1];
              }
              ans=max(ans,rightLen+leftLen+1);
            }
        }
    }
    return ans;
  }
};