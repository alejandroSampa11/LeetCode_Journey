class Solution {
public:
    bool dp(string& s, int start, int end, vector<vector<int>>& memo) {
        if(memo[start][end] != -1) return memo[start][end];
        if(start >= end) return true;
        if(end-start+1>=2 && s[start] != s[end]) return false;
        
        memo[start][end] = dp(s,start+1,end-1, memo);
        return memo[start][end];
    }

    string longestPalindrome(string s) {
        vector<vector<int>> memo(s.size() + 1, vector<int>(s.size() + 1, -1));
        string resu = "";
        for(int i = 0; i<s.size(); i++){
            for(int j = i; j<s.size(); j++){
                if(dp(s,i,j, memo) && (j-i+1 > resu.size())){
                    resu = s.substr(i, j-i+1);
                }
            }
            
        }
        return resu;
    }
};