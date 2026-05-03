class Solution {
public:
    vector<int> findValidElements(vector<int>& v) {
        int n=v.size();
        int maxiL=v[0];
        int maxiR=v[n-1];
        vector<int>ans;
        ans.push_back(v[0]);
        vector<int>maxi=v;
        for(int i=n-2;i>=1;i--){
            maxi[i]=maxiR;
            maxiR=max(maxiR,v[i]);
        }
        for(int i=1;i<n-1;i++){
            if(v[i]>maxiL || v[i]>maxi[i]) ans.push_back(v[i]);
            maxiL=max(maxiL,v[i]);
        }
        if(n>1)ans.push_back(v[n-1]);
        return ans;
    }
};