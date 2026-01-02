class Solution {
public:

    bool isPalindrome(vector<string>& path){
        for(string x : path){
            if(x.size() == 1) continue;
            for(int i = 0; i<x.size()/2; i++){
                if(x[i] != x[x.size()-1-i]) return false;
            }
        }
        return true;
    }

    void backtracking(vector<vector<string>>& resu, string s, int start, vector<string>& path){
        if(start == s.size()){
            if(isPalindrome(path)) resu.push_back(path);
            return;
        }
        
        for(int i = start; i<s.size(); i++){
            string cut = s.substr(start, i-start+1);
            path.push_back(cut);
            backtracking(resu, s, i+1, path);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> resu;
        vector<string> path;
        backtracking(resu, s, 0, path);

        return resu;
    }
};