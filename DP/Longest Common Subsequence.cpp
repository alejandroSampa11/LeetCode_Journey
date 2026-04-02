class Solution {
public:

    map<pair<int,int>, int> memo;
    int dp(string& text1, string& text2, int pos1, int pos2){
        if(memo.count({pos1, pos2})) return memo[{pos1, pos2}];
        if(pos2 == text2.size()) return 0;
        if (pos1 == text1.size() || pos2 == text2.size()) return 0;
        if(pos1 == text1.size() && pos2<text2.size()) return 0;


        int resu = 0;
        int op1 = 0;
        int op2 = 0;
        if(text1[pos1] == text2[pos2]){
            resu = 1 + dp(text1, text2, pos1+1, pos2+1);
        }else{
            op1 = dp(text1, text2, pos1+1, pos2);
            op2 = dp(text1, text2, pos1, pos2+1);
            resu = max(op1, op2);
        }

        memo[{pos1, pos2}] = resu;
        return memo[{pos1, pos2}];
    }

    int longestCommonSubsequence(string text1, string text2) {
        return dp(text1, text2, 0,0);
    }
};