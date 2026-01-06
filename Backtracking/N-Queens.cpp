class Solution {
public:

    void backtracking(vector<string>& path, vector<vector<string>>&resu, vector<bool>& column, int fila,  vector<bool>& diagPrin, vector<bool>& diagSec){
        if(fila == path.size()){
            resu.push_back(path);
            return;
        }
        for(int i = 0; i<path.size(); i++){
            if(column[i]) continue;
            if(diagPrin[fila-i+path.size()]) continue;
            if(diagSec[fila+i]) continue;
            path[fila][i] = 'Q';
            column[i] = true;
            diagPrin[fila-i+path.size()] = true;
            diagSec[fila+i] = true;
            backtracking(path, resu, column, fila+1, diagPrin, diagSec);
            path[fila][i] = '.';
            diagPrin[fila-i+path.size()] = false;
            diagSec[fila+i] = false;
            column[i] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string base = "";
        for(int i = 0; i<n; i++){
            base+=".";
        }
        vector<vector<string>> resu;
        vector<string> path(n, base);
        vector<bool> column(n, false);
        vector<bool> diagPrin(2*n-1, false);
        vector<bool> diagSec(2*n-1, false);
        backtracking(path, resu, column, 0, diagPrin, diagSec);
        return resu;
    }
};