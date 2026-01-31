class Solution {
public:

    map<pair<int,int>, int> memo;
    int dp(int row, int column, int finalR, int finalC){
        if(memo.count({row, column})) return memo[{row, column}];
        if(row == finalR && column == finalC) return 1;
        if(row>finalR || column>finalC) return 0;

        int resu = dp(row+1, column, finalR, finalC) + dp(row, column+1, finalR, finalC);
        memo[{row, column}] = resu;

        return memo[{row, column}];
    }

    int uniquePaths(int m, int n) {
        return dp(0,0,m-1,n-1);
    }
};