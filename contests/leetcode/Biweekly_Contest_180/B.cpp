class Solution {
using ll=long long;
public:
    int countDigitOccurrences(vector<int>& v, int digit) {
        int n=v.size();
        ll ans=0;
        for(auto &ele:v){
            string s=to_string(ele);
            for(auto &i:s){
                if(i==(digit+'0')){
                    ans++;
                }
            }
        }
        return ans;
    }
};