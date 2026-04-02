class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] == 0)
            return;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++) {
            dfs(grid, i + dx[k], j + dy[k]);
        }
    }

    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid1[i][j] == 0 && grid2[i][j] == 1) {
                    dfs(grid2, i, j);
                }
            }
        }

        int resu = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1) {
                    dfs(grid2, i, j);
                    resu++;
                }
            }
        }

        
        return resu;
    }
};