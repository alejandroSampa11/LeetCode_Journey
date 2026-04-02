class Solution {
public:

    map<pair<int,int>, int> memo;
    int dp(vector<int>& prices, int pos, int state){
        if(memo.count({pos, state})) return memo[{pos, state}];
        if(pos == prices.size()) return 0;

        int resu = 0;
        //BUY
        if(state == 0){
            resu =  max(dp(prices, pos+1, 1) - prices[pos], dp(prices, pos+1, 0));
        }
        // VENDER
        if(state == 1){
            resu =  max(dp(prices, pos+1,2) + prices[pos], dp(prices, pos+1,1));
        }
        // SOLD
        if(state == 2){
            resu = dp(prices, pos+1, 0);
        }

        return memo[{pos, state}] = resu;
    }

    int maxProfit(vector<int>& prices) {
        return dp(prices,0,0);
    }
};