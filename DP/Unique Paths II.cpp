class Solution {
public:

    map<pair<int,int>, int> memo;
    int dp(int row, int column, vector<vector<int>>& grid){
        if(memo.count({row,column})) return memo[{row, column}];
        if(row > grid.size()-1 || column > grid[0].size()-1) return 0;
        if(grid[row][column] == 1) return 0;
        if(row == grid.size()-1 && column == grid[0].size()-1) return 1;

        memo[{row, column}] = dp(row+1, column, grid) + dp(row, column+1, grid);
        return memo[{row, column}];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return dp(0,0, obstacleGrid);
    }
};