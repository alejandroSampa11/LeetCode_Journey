class Solution {
public:

    bool dp(string& s, string& p, int pos1, int pos2, vector<vector<int>>& memo){
        if(memo[pos1][pos2] != -1) return memo[pos1][pos2] == 1 ? true : false;
        if(s.size() == pos1 && p.size() == pos2) return true;
        if(pos2 == p.size() && pos1<s.size()) return false;

        bool resu = false;
        if((pos1<s.size()) && (s[pos1] == p[pos2] || p[pos2] == '?')){
            resu = dp(s, p, pos1+1, pos2+1,memo);
        }else if(p[pos2] == '*'){
            bool op1 = (pos1<s.size()) && dp(s,p, pos1+1, pos2, memo); 
            bool op2 = dp(s,p,pos1, pos2+1, memo);
            resu = op1 || op2;
        }else{
            resu = false;
        }
        return memo[pos1][pos2] = resu;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dp(s,p,0,0, memo);
    }
};