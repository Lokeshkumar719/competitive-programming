class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        int lo = 0, hi = m;
        int elementReqd = (m + n + 1) / 2;
        while (lo <= hi) {
            // number of elements choosen from smaller vector
            int mid = lo + (hi - lo) / 2;

            // index of the left half
            int l1 = mid - 1;
            int l2 = elementReqd - mid - 1;

            int r1 = l1 + 1;
            int r2 = l2 + 1;

            int leftEle1 = (l1 >= 0) ? nums1[l1] : INT_MIN;
            int leftEle2 = (l2 >= 0) ? nums2[l2] : INT_MIN;

            int rightEle1 = (r1 < m) ? nums1[r1] : INT_MAX;
            int rightEle2 = (r2 < n) ? nums2[r2] : INT_MAX;

            // condition for median
            if (leftEle1 <= rightEle2 && leftEle2 <= rightEle1) {
                if ((m + n) & 1)
                    return max(leftEle1, leftEle2);
                return (max(leftEle1, leftEle2) + min(rightEle1, rightEle2)) /
                       2.0;
            } else if (leftEle1 > rightEle2) {
                hi = mid - 1;
            } else if (leftEle2 > rightEle1) {
                lo = mid + 1;
            }
        }
        return -1;
    }
};