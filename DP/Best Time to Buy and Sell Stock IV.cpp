class Solution {
public:
    int dp(vector<int>& prices, int pos, int status, int k,vector<vector<vector<int>>>& memo) {
        if (memo[pos][status][k] != -1) return memo[pos][status][k];
        if (k == 0) return 0;
        if (pos == prices.size()) return 0;

        int resu = 0;
        // BUY
        if (status == 0) {
            resu = max(dp(prices, pos + 1, 1, k, memo) - prices[pos],
                       dp(prices, pos + 1, 0, k, memo));
        }
        // SELL
        if (status == 1) {
            resu = max(dp(prices, pos + 1, 0, k - 1, memo) + prices[pos],
                       dp(prices, pos + 1, 1, k, memo));
        }

        return memo[pos][status][k] = resu;
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> memo(prices.size() + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return dp(prices, 0, 0, k, memo);
    }
};