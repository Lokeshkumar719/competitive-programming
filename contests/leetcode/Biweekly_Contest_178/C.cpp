class Solution {
public:
  int minCost(vector<int>& nums1, vector<int>& nums2) {
    int n=nums1.size();
    int ans=0;
    map<int,int>mp1;
    map<int,int>mp2;
    for(int i=0;i<n;i++){
      mp1[nums1[i]]++;
      mp2[nums2[i]]++;
    }
    for(auto &it:mp1){
      int ele=it.first;
      if((mp2[ele]+mp1[ele])&1) return -1;
      ans+=max(0,(mp1[ele]-mp2[ele])/2);
    }
    for(auto &it:mp2){
      int ele=it.first;
      if(mp1[ele]==0 && (it.second&1)) return -1;
    }
    return ans;
  }
};