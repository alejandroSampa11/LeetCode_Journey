class Solution {
public:
    unordered_map<int,int> memo;

    int dp(int pos, vector<int>& cost){
        if(memo.count(pos)) return memo[pos]; 
        if(pos <= 0) return 0;
        int resu = INT_MAX;
        if(pos-1>=0){
            resu = min(dp(pos-1, cost) + cost[pos-1] + ((pos-(pos-1))*(pos-(pos-1))), resu);
        }
        if(pos-2>=0){
            resu = min(dp(pos-2, cost) + cost[pos-1] + ((pos-(pos-2))*(pos-(pos-2))), resu);
        }
        if(pos-3>=0){
            resu = min(dp(pos-3, cost) + cost[pos-1] + ((pos-(pos-3))*(pos-(pos-3))), resu);
        }
        memo[pos] = resu;
        return memo[pos];
    }

    int climbStairs(int n, vector<int>& costs) {
        return dp(n, costs);
    }
};