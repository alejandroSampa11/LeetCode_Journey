class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }

        if(freshOranges == 0) return 0;

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,-1,1};

        int min = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                for(int i = 0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny] !=0){
                        if(grid[nx][ny] == 1){
                            q.push({nx, ny});
                            grid[nx][ny] = 2;
                            freshOranges--;
                        }
                    }
                }
            }
            min++;
        }
        return freshOranges == 0 ? min-1 : -1;
    }
};