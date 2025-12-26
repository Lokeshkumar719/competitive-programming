class Solution {
public:
    int getLeastFrequentDigit(int n) {
        int ans=INT_MAX;
        int freq=INT_MAX;
        unordered_map<int,int>mp;
        while(n!=0){
            int last=n%10;
            mp[last]++;
            n/=10;
        }
        for(auto &it:mp){
            if(it.second<freq){
                freq=it.second;
                ans=it.first;
            }else if(freq==it.second){
                if(it.first<ans){
                    ans=it.first;
                }
            }
        }
        return ans;
    }
};