class Solution {
public:

    int dp(int step, unordered_map<int,int>& memo){
        if(memo.count(step)) return memo[step];
        if(step<0) return 0;
        if(step == 0) return 1;
        int ways = dp(step-1, memo) + dp(step-2, memo);
        
        return memo[step] = ways;

    }

    int climbStairs(int n) {
        unordered_map<int,int> memo;
        return dp(n, memo);
    }
};