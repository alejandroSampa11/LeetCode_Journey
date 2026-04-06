class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> computerR(m, 0);
        vector<int> computerC(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    computerR[i]++;
                    computerC[j]++;
                }
            }
        }

        int resu = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (computerR[i] > 1 || computerC[j] > 1) {
                        resu++;
                    }
                }
            }
        }
        return resu;
    }
};