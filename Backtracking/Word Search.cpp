class Solution {
public:

    bool findLetter(vector<vector<char>>& board, string& word, int x, int y, int pos, vector<vector<bool>>& used){
        if(y>=board[0].size()|| x<0 || x>=board.size() || y<0) return false;
        if(word[pos] != board[x][y]) return false;
        if(used[x][y]) return false;
        if(pos+1 == word.size()) return true; 
        used[x][y] = true;
        bool izq = findLetter(board, word, x-1,y,pos+1,used);
        bool der = findLetter(board, word, x+1,y,pos+1, used);
        bool abajo = findLetter(board, word, x,y-1,pos+1, used);
        bool arriba = findLetter(board, word, x,y+1,pos+1, used);
        used[x][y] = false;
        return izq || der || abajo || arriba;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> used (board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0;i<board.size(); i++){
            for(int j =0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(findLetter(board, word, i,j,0, used)) return true;
                }
            }
        }
        return false;
    }
};