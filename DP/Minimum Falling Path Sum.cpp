class Solution {
public:

    int dp(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& memo){
        if(y<0 || y>=matrix[0].size()) return 1e9;
        if(x == matrix.size()) return 0;
        if (memo[x][y] != 1e9 + 7) return memo[x][y];

        int izq = dp(x+1, y-1, matrix, memo);
        int der = dp(x+1, y+1, matrix, memo);
        int centro = dp(x+1, y, matrix, memo);

        return memo[x][y] = matrix[x][y] + min({izq ,der, centro});

    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> memo(matrix.size()+1, vector<int>(matrix.size()+1, 1e9 + 7));
        int resu = INT_MAX;
        for(int i = 0; i<matrix.size(); i++){
            resu = min(resu, dp(0,i, matrix, memo));
        }
        return resu;
    }
};