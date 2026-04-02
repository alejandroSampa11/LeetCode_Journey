class Solution {
public:
    int dp(vector<int>& prices, int pos, int state, int trans, vector<vector<vector<int>>>& memo) {
        if (memo[pos][state][trans] != -1)
            return memo[pos][state][trans];
        if (trans == 0)
            return 0;
        if (pos == prices.size())
            return 0;

        int resu = 0;
        if (state == 0) {
            resu = max(dp(prices, pos + 1, 1, trans, memo) - prices[pos],
                       dp(prices, pos + 1, 0, trans, memo));
        }
        if (state == 1) {
            resu = max(dp(prices, pos + 1, 0, trans - 1, memo) + prices[pos],
                       dp(prices, pos + 1, 1, trans, memo));
        }

        return memo[pos][state][trans] = resu;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> memo(
            prices.size()+1, vector<vector<int>>(2, vector<int>(3, -1)));
        if(prices.empty()) return 0;
        return dp(prices, 0, 0, 2, memo);
    }
};