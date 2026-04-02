class Solution {
public:
    vector<int> bfs(vector<vector<int>>& land, int x, int y) {
        int maxX = x;
        int maxY = y;
        queue<pair<int, int>> q;
        q.push({x, y});
        land[x][y] = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [qx, qy] = q.front();
            q.pop();
            maxX = max(maxX, qx);
            maxY = max(maxY, qy);

            for (int i = 0; i < 4; i++) {
                int nx = qx + dx[i];
                int ny = qy + dy[i];
                if(nx>=0 && nx<land.size() && ny>=0 && ny<land[0].size() && land[nx][ny] == 1){
                    land[nx][ny] = 0;
                    q.push({nx,ny});
                }
            }
        }
        return {x,y,maxX,maxY};
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> resu;
        for(int i = 0; i<land.size(); i++){
            for(int j = 0; j<land[0].size(); j++){
                if(land[i][j] == 0) continue;
                resu.push_back(bfs(land,i,j));
            }
        }
        return resu;
    }
};