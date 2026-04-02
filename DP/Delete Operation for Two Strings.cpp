class Solution {
public:

    map<pair<int,int>, int> memo;
    int dp(string&word1, string& word2, int pos1, int pos2){
        if(memo.count({pos1, pos2})) return memo[{pos1, pos2}];
        if(pos1 == word1.size() && pos2 == word2.size()) return 0;
        if(pos1 == word1.size() && pos2 < word2.size()) return word2.size() - pos2;
        if(pos1 < word1.size() && pos2 == word2.size()) return word1.size() - pos1;

        int resu = INT_MAX;
        if(word1[pos1] == word2[pos2]){
            resu = dp(word1, word2, pos1+1, pos2+1);
        }else{
            int op1 = dp(word1, word2, pos1+1, pos2) + 1;
            int op2 = dp(word1, word2, pos1, pos2+1) + 1;

            resu = min(op1,op2);
        }
        return memo[{pos1,pos2}] = resu;

    }

    int minDistance(string word1, string word2) {
        return dp(word1, word2, 0, 0); 
    }
};