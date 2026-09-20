class Solution {
public:
    bool isRectangleOverlap(vector<int>& a, vector<int>& b) {
        int cw = min(a[2], b[2]) - max(a[0], b[0]);
        int ch = min(a[3], b[3]) - max(a[1], b[1]);
        return cw > 0 && ch > 0;
    }
};