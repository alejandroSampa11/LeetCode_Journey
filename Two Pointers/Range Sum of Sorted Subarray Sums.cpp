class Solution {
public:
    const int MOD = 1e9 + 7;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> all;
        for(int i = 0; i<n; i++){
            int sum = 0;
            for(int j = i; j<n; j++){
                sum+=nums[j];
                all.push_back(sum);
            }
        }
        sort(all.begin(), all.end());
        long long sumTotal = 0;
        for(int i = left-1; i<right; i++){
            sumTotal+=all[i];
        }
        return sumTotal%MOD;
    }
};