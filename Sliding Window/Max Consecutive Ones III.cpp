class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0;
        int ks = 0;
        int maxLength = 0;
        for (int end = 0; end < n; end++) {
            if (!nums[end]) {
                ks++;
            }

            while (ks > k && start < end) {
                if(!nums[start]){
                    ks--;
                }
                start++;
            }

            if(ks<=k){
                maxLength = max(maxLength, end-start+1);
            }
        }
        return maxLength;
    }
};