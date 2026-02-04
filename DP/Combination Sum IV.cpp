class Solution {
public:

    unordered_map<int, int> memo;
    int dp(vector<int>& nums, int target){
        if(memo.count(target)) return memo[target];
        if(target == 0) return 1;
        if(target<0) return 0;

        int resu = 0;
        for(int i = 0; i<nums.size(); i++){
            resu+= dp(nums, target-nums[i]);
        }
        memo[target] = resu;
        return memo[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        return dp(nums, target);
    }
};