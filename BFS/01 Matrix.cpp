class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        vector<vector<int>> dist(mat.size(), vector<int>(mat[0].size(), -1));
        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
                if(mat[i][j] != 0) continue;
                dist[i][j] = 0;
                q.push({i,j});
            }
        }

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i<4; i++){
                int nr = x + dr[i];
                int nc = y + dc[i];
                if(nr>=0 && nr<mat.size() && nc>=0 && nc<mat[0].size() && dist[nr][nc] == -1){
                    dist[nr][nc] = dist[x][y] + 1;
                    q.push({nr,nc});
                }
            }
        }

        return dist;
    }
};