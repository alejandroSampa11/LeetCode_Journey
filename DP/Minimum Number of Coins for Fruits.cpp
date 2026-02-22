class Solution {
public:

    int dp(vector<int>& prices, vector<int>& memo, int pos){
        if(pos >= prices.size()) return 0;
        if(memo[pos] != -1) return memo[pos];
        
        int resu = INT_MAX;
        int idxFree = pos + (pos+1);
        for(int i = pos+1; i<=idxFree+1; i++){
            resu = min(resu, prices[pos] + dp(prices, memo, i));
        }

        return memo[pos] = resu;
    }

    int minimumCoins(vector<int>& prices) {
        vector<int> memo (prices.size()+1,-1);
        return dp(prices, memo, 0);
    }
};