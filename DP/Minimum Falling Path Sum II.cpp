class Solution {
public:

    int dp(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& memo){
        if(x == grid.size()) return 0;
        if(memo[x][y] != 1e9+7) return memo[x][y];

        int resu = INT_MAX;
        bool availableColumn = false;
        for(int i = 0; i<grid[x].size(); i++){
            if(i == y) continue;
            availableColumn = true;
            resu = min(resu, dp(grid, x+1,i, memo));
        }
        if (!availableColumn) resu = 0;
        return memo[x][y] = resu + grid[x][y];
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), 1e9+7));
        int resu = INT_MAX;
        for (int i = 0; i < grid.size(); i++) {
            resu = min(resu, dp(grid,0,i,memo));
        }
        return resu;
    }
};