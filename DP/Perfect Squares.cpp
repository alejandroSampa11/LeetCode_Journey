class Solution {
public:

    unordered_map<int,int> memo;
    int dp(int valor, vector<int>& squares){
        if(memo.count(valor)) return memo[valor];
        if(valor == 0) return 0;
        if(valor<0) return INT_MAX;

        int resu = INT_MAX;
        for(int i = 0; i<squares.size(); i++){
            int x = dp(valor-squares[i], squares);
            if(x != INT_MAX){
                x++;
            }
            resu = min(x, resu);
        }
        memo[valor] = resu;
        return memo[valor];
    }

    int numSquares(int n) {
        vector<int> squares;
        for(int i = 1; i*i<=n; i++){
            squares.push_back(i*i);
        }
        return dp(n, squares);
    }
};