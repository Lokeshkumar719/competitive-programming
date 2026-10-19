class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int>q;
        for(int i=1;i<=8;i++) q.push(i);
        vector<int>ans;
        while(!q.empty()){
            int num=q.front();
            q.pop();
            if(num>high) return ans;
            if(num>=low && num<=high) ans.push_back(num);
            int last_digit=num%10;
            if(last_digit==9) continue;
            num*=10;
            num+=(last_digit+1);
            q.push(num);
        }
        return ans;
    }
};