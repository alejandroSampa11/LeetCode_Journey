class Solution {
public:

    
    int dp(string& s, int start, int end, vector<vector<int>>& memo){
        if(memo[start][end] != -1) return memo[start][end];
        if(start > end) return 0;
        if(start == end) return 1;

        int resu = 0;
        if(s[start] == s[end]){
            resu = 2 + dp(s, start+1, end-1, memo);
        }else{
            resu = max(dp(s,start+1,end,memo), dp(s,start, end-1, memo));
        }

        return memo[start][end] = resu;
    }

    int longestPalindromeSubseq(string s) {
        vector<vector<int>> memo(s.size()+1, vector<int>(s.size()+1, -1));    
        int resu = 0;
        for(int i = 0; i<s.size(); i++){
            for(int j = i; j<s.size(); j++){
                resu = max(resu, dp(s,i,j,memo));
            }
        }
        return resu;
    }
};