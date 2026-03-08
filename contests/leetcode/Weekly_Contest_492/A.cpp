class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n=capacity.size();
        int idx=-1;
        for(int i=0;i<n;i++){
            if(capacity[i]>=itemSize && idx==-1){
                idx=i;
            }else if(capacity[i]>=itemSize && capacity[i]<capacity[idx]) idx=i;
        }
        return idx;
    }
};
