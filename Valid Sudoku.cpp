class Solution {
public:

    bool existeCombinacion(map<char, vector<pair<int, int>>> &resu, char c, pair<int, int> comb) {
    if (resu.find(c) != resu.end()) {
        for (const auto &str : resu[c]) {
            if (comb == str) {
                return true;
            }
        }
    }
    return false;
}

    bool isValidSudoku(vector<vector<char>>& board) {
        //checar por fila
        for(int i = 0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                for(int k=j+1;k<board[i].size();k++){
                    if(board[i][j]== '.'){
                        continue;
                    }
                    if(board[i][j]==board[i][k]){
                        cout<<"1ER"<<endl;
                        return false;
                    }
                }
            }
        }

        //checar por columna
        for(int i = 0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                for(int k=j+1;k<board[i].size();k++){
                    if(board[j][i]== '.'){
                        continue;
                    }
                    if(board[j][i]==board[k][i]){
                        cout<<"2ER"<<endl;
                        return false;
                    }
                }
            }
        }

        map<char,vector<pair<int,int>>>resu;
        for(int i = 0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='.'){
                    continue;
                }
                pair<int,int>par;
                if(i<3 && j<3){
                    par = {0, 0}; 
                }else if(i<3 && j<6){
                    par = {0, 1};
                }else if(i<3 && j<9){
                    par = {0, 2};
                }
                else if(i<6 && j<3){
                    par = {1, 0};
                }else if(i<6 && j<6){
                    par = {1, 1};
                }else if(i<6 && j<9){
                    par = {1, 2};
                }else if(i<9 && j<3){
                    par = {2, 0};
                }else if(i<9 && j<6){
                    par = {2, 1};
                }else if(i<9 && j<9){
                    par = {2, 2};
                }
                if(existeCombinacion(resu, board[i][j], par)){
                    cout<<"3ER"<<endl;
                    return false;
                }
                resu[board[i][j]].push_back(par);
            }
        }
        return true;
    }
};
