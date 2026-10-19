class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s(nums.begin(),nums.end());
        int maxi=0;
        for(int ele:s){
            int num=ele;
            if(s.find(num+1)==s.end()){
                int len=0;
                while(s.find(num)!=s.end()){
                    len++;
                    num--;
                }
                maxi=max(maxi,len);
            }     
        }
        return maxi;
    }
};