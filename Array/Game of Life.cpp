class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> copy = board;
        int m = board.size();
        int n = board[0].size();

        int dx[] = {0,0,-1,1,-1,-1,1,1};
        int dy[] = {-1,1,0,0,-1,1,-1,1};

        for(int i = 0 ; i <m; i++){
            for(int j = 0; j<n; j++){
                int lives = 0;
                int dead = 0;
                int cell = 0;
                for(int s = 0; s<8; s++){
                    int nx = i + dx[s];
                    int ny = j + dy[s];

                    if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
                    if(copy[nx][ny] == 1){
                        lives++;
                    }
                    if(copy[nx][ny] == 0){
                        dead++;
                    }
                }
                if(board[i][j] == 1 && lives<2){
                    board[i][j] = 0;
                }
                else if(board[i][j] == 1 && (lives>=2 && lives<=3)){
                    board[i][j] = 1;
                }else if(board[i][j] == 1 && lives>3){
                    board[i][j] = 0;
                }else if(board[i][j] == 0 && lives==3){
                    board[i][j] = 1;
                }
            }
        }
    }
};