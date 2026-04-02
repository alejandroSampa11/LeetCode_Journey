class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};
        int xClick = click[0];
        int yClick = click[1];
        if(board[xClick][yClick] == 'M'){
            board[xClick][yClick] = 'X';
            return board;
        }
        queue<pair<int, int>> q;
        q.push({xClick, yClick});
        board[xClick][yClick] = 'B';
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            int mines = 0;
            for (int i = 0; i < 8; i++) {
                int nx = x + dr[i];
                int ny = y + dc[i];
                if (nx >= 0 && nx < board.size() && ny >= 0 &&
                    ny < board[0].size() && board[nx][ny] == 'M') {
                    mines++;
                }
            }

            if (mines > 0) {
                board[x][y] = mines + '0';
            } else {
                for (int i = 0; i < 8; i++) {
                    int nx = x + dr[i];
                    int ny = y + dc[i];
                    if (nx >= 0 && nx < board.size() && ny >= 0 &&
                        ny < board[0].size() && board[nx][ny] == 'E') {
                        board[nx][ny] = 'B';
                        q.push({nx, ny});
                    }
                }
            }
        }
        return board;
    };
};