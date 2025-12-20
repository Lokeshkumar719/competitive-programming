class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>v=nums;
        sort(v.begin(),v.end(),[](int a,int b){
            return abs(a)>abs(b);
        });
        int maxi=v[0];
        long long ans =(long long) abs(maxi)*abs(v[1])*100000;
        return ans;
        return -1;
    }
};