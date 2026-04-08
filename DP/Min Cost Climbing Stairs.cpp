class Solution {
public:
    unordered_map<int,int> memo;
    int dp(vector<int>& cost, int pos){
        if(pos<0) return 0;
        if(memo.count(pos)) return memo[pos];

        int oneStep = dp(cost, pos-1);
        int twoSteps = dp(cost, pos-2);

        return memo[pos] = min(oneStep, twoSteps) + cost[pos];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        return min(dp(cost, cost.size()-1), dp(cost, cost.size()-2));
    }
};