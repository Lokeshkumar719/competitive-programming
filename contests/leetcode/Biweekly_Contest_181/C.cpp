class Solution {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<int>>graph(n);
        for(auto &it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        int ans=0;
        for(int m=1;m<(1<<n);m++){
            int sum=0,num_nodes=0;
            for(int i=0;i<n;i++){
                if(m&(1<<i)){
                    sum+=nums[i];
                    num_nodes++;
                }
            }
            if(sum&1) continue;
            vector<bool>vis(n,false);
            queue<int>q;
            for(int i=0;i<n;i++){
                if(m&(1<<i)){
                    q.push(i);
                    vis[i]=true;
                    break;
                }
            }
            int cnt=0;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                cnt++;
                for(auto &v:graph[u]){
                    if((m&(1<<v)) && !vis[v]){
                        q.push(v);
                        vis[v]=true;
                    }
                }
            }
            if(cnt==num_nodes) ans++;
        }
        return ans;
    }
};