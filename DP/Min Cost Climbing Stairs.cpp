class Solution {
public:

    unordered_map<int,int> memo;

    int dp(vector<int>& cost, int pos){
        if(memo.count(pos)) return memo[pos];
        if(pos == 0) return cost[0];
        if(pos == 1) return cost[1]; 
        
        memo[pos] = min(dp(cost, pos-1), dp(cost,pos-2)) + cost[pos];
        return memo[pos]; 
    }

    int minCostClimbingStairs(vector<int>& cost) {
        return min(dp(cost, cost.size()-1), dp(cost, cost.size()-2));
    }
};