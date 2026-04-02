class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<vector<int>> dist(grid.size(), vector<int>(grid.size(), -1));
        queue<pair<int,int>> q;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};


        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        int ans = -1;
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int i = 0; i<4; i++){
                int nr = x + dr[i];
                int nc = y + dc[i];
                if(nr>= 0 && nr<grid.size() && nc>=0 && nc<grid.size() && dist[nr][nc] == -1){
                    dist[nr][nc] = dist[x][y] + 1;
                    ans = max(ans, dist[nr][nc]);
                    q.push({nr, nc});
                }
            }

        }

        return ans;
    }
};