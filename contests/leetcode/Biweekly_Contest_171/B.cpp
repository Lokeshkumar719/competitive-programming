class Solution {
public:
    bool isPal(int n){
        string s="";
        while(n){
            if(n&1) s="1"+s;
            else s="0"+s;
            n/=2;
        }
        int i=0,j=s.size()-1;
        while(i<s.size() && s[i]=='0') i++;
        
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else return false;
        }
        
        return true;
    }
    vector<int> minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<=nums[i];j++){
                if( isPal(nums[i]-j) || isPal(nums[i]+j) ){
                    ans[i]=j;
                    break;
                }
            }
        }
        return ans;
    }
};