class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int xStart = row;
        int yStart = col;
        int originalColor = grid[xStart][yStart];
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,-1,1};
        vector<vector<bool>> visited (grid.size(), vector<bool>(grid[0].size(), false));
        vector<vector<int>> resu = grid;
        queue<pair<int,int>> q;

        q.push({xStart, yStart});

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            
            for(int i = 0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>= 0 && nx<grid.size() && ny>= 0 && ny<grid[0].size() && !visited[nx][ny]){
                    if(originalColor != grid[nx][ny]){
                        resu[x][y] = color;
                        visited[x][y] = true;
                    }
                    if(originalColor == grid[nx][ny]){
                        visited[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
                if(nx<0 || nx>=grid.size() || ny<0 || ny>=grid[0].size()){
                    resu[x][y] = color;
                    visited[x][y] = true;   
                }
            }

        }
        return resu;
    }
};