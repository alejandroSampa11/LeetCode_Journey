class Solution {
public:
    void backtracking(int open, int closed, string& path,
                      vector<string>& resu) {
        if (open == 0 && closed == 0) {
            resu.push_back(path);
            return;
        }
        if (closed < 0 || open < 0)
            return;
        if (closed < open)
            return;

        if (open - 1 >= 0) {
            path += "(";
            backtracking(open - 1, closed, path, resu);
            path.pop_back();
        }
        if (closed - 1 >= 0) {
            path += ")";
            backtracking(open, closed - 1, path, resu);
            path.pop_back();
        }

        // for(int i = 0; i<2; i++){
        //     if(parentheses[i] == '('){
        //         path+="(";
        //         backtracking(open-1, closed, path, resu, parentheses);
        //         path.pop_back();
        //     }else{
        //         path+=")";
        //         backtracking(open, closed-1, path, resu, parentheses);
        //         path.pop_back();
        //     }
        // }
    }

    vector<string> generateParenthesis(int n) {
        string path = "";
        // string parentheses = "()";
        vector<string> resu;
        backtracking(n, n, path, resu);
        return resu;
    }
};