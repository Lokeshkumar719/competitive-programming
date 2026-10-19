class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int>ans(n);
        stack<int>s;
        s.push(heights[n-1]);
        ans[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int cnt=0;
            while(s.size()>0 && s.top()<heights[i]){
                s.pop();
                cnt++;
            }
            if(s.size()!=0)cnt++;
            ans[i]=cnt;
            s.push(heights[i]);
        }
        return ans;

    }
};