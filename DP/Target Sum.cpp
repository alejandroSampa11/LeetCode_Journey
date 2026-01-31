class Solution {
public:

    map<pair<int,int>,int> memo;
    int dp(vector<int>&nums, int target, int pos, int suma){
        if(memo.count({pos, suma})) return memo[{pos,suma}];
        if(pos == nums.size() && suma == target) return 1;
        if(pos == nums.size() && suma != target) return 0;

        memo[{pos, suma}] = dp(nums,target, pos+1, suma+nums[pos]) + dp(nums,target, pos+1, suma-nums[pos]);
        return memo[{pos, suma}];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return dp(nums, target, 0, 0);
    }
};  