class Solution {
public:

    unordered_map<int,int> memo;
    int dp(vector<int>& coins, int amount){
        if(amount<0) return INT_MAX;
        if(amount == 0) return 0;
        if(memo.count(amount)) return memo[amount];
        
        int numCoins = INT_MAX;
        for(int i = 0; i<coins.size(); i++){
            if(amount - coins[i]>=0){
                int x = dp(coins, amount-coins[i]);
                if(x != INT_MAX){
                    x++;
                } 
                numCoins = min(numCoins,x);
                
            }
        }
        memo[amount] = numCoins;
        return memo[amount];

    }

    int coinChange(vector<int>& coins, int amount) {
        int resu = dp(coins, amount);
        return resu == INT_MAX ? -1 : resu;
    }
};