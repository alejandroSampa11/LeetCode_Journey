class Solution {
public:

    unordered_map<int,int> memo;
    int dp(vector<int>&nums, int pos){
        if(memo.count(pos)) return memo[pos];
        if(pos>= nums.size()) return 0;
        int noRobar = dp(nums, pos+1);
        int robar = dp(nums, pos+2) + nums[pos];
        memo[pos] = max(noRobar, robar);
        return memo[pos];
    }

    int rob(vector<int>& nums) {
        return dp(nums, 0);
    }
};