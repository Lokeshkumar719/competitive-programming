class Solution {
	public:
	int longestBitonicSequence(int n, vector<int> &nums) {
	    // calculate the LIS ending at index i
		vector<int>dp_I(n, 1);
		for (int i = 1; i<n; i++) {
			for (int j = 0; j<i; j++) {
				if (nums[j]<nums[i]) {
					dp_I[i] = max(dp_I[i],1+dp_I[j]);
				}
			}
		}
	    // calculate the LDS starting at index i 
		vector<int>dp_D(n, 1);
		for (int i = n - 2; i >= 0; i--) {
			for (int j = i + 1; j<n; j++) {
				if (nums[j]<nums[i]) {
					dp_D[i] =max(dp_D[i],1+dp_D[j]);
				}
			}
		}
	    // now check the answer (remeber about -1 as that index is counted in both)
	    // also bitionic subsequence is possible only if both LIS and LDS has length > 1 at that index
		int ans = 0;
		for (int i = 0; i<n; i++) {
		    if(dp_I[i] >1 && dp_D[i]>1){
	            	int len = dp_I[i] + dp_D[i] - 1;
			        ans = max(ans, len);
		    }
		}
		
		return ans;
	}
};
