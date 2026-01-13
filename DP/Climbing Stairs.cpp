class Solution {
public:
    unordered_map<int,int> memo;
    int climbStairs(int n) {
        if(memo.count(n)) return memo[n];
        if(n == 1) return 1;
        if(n == 2) return 2;
        memo[n] = climbStairs(n-1) + climbStairs(n-2);
        return memo[n];
    }
};