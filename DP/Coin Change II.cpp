class Solution {
public:

    map<pair<int,int>,int> memo;
    int dp(vector<int>& coins, int amount, int start){
        if(memo.count({amount, start})) return memo[{amount, start}];
        if(amount == 0) return 1;
        if(amount < 0) return 0;
        

        int resu = 0;
        for(int i = start; i<coins.size(); i++){
            resu+=dp(coins, amount-coins[i], i);
        }
        memo[{amount, start}] = resu;
        
        return memo[{amount,start}];
    }

    int change(int amount, vector<int>& coins) {
        return dp(coins,amount, 0);
    }
};