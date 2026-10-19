class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(ans.size() == 0 || ans.back() < 0 || (ans.back() >0 && ast[i]>0)){
                ans.push_back(ast[i]);
                continue;
            }
            // collision is possible only when ans.back()>0  and ast[i]<0

            bool check = true;
            while(ans.size() && ans.back()>0 && ast[i]<0){
                int dirc = ans.back() + ast[i];
                if(!dirc){
                    ans.pop_back();
                    check = false;
                    break;
                }else if(dirc>0){
                    check = false;
                    break;
                }else{
                    ans.pop_back();
                }
            }

            if(check)
                ans.push_back(ast[i]);
        }

        return ans;
    }
};