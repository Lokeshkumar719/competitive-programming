class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n=order.size();
        unordered_set<int>s;
        for(int i=0;i<friends.size();i++){
            s.insert(friends[i]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(s.find(order[i])!=s.end()){
                ans.push_back(order[i]);
            }
        }
        return ans;
    }
};