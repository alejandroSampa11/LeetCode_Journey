class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int xStart = 0;
        int yStart = 0;
        int n = grid.size();
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        bool found = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    xStart = i;
                    yStart = j;
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }

        grid[xStart][yStart] = 2;
        queue<pair<int, int>> q;
        queue<pair<int, int>> island;
        q.push({xStart, yStart});
        island.push({xStart, yStart});

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    island.push({nx, ny});
                }
            }
        }
        int resu = 0;
        while (!island.empty()) {
            int size = island.size();
            while (size--) {
                auto [xIsland, yIsland] = island.front();
                island.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = xIsland + dx[i];
                    int ny = yIsland + dy[i];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        if (grid[nx][ny] == 1)
                            return resu;
                        if (grid[nx][ny] == 0) {
                            grid[nx][ny] = 2;
                            island.push({nx, ny});
                        }
                    }
                }
            }
            resu++;
        }

        return resu;
    }
};