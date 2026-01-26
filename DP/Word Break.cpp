class Solution {
public:

    unordered_map<int,bool> memo;
    bool dp(string s, int pos, unordered_set<string>& dict){
        if(pos == s.size()) return true;
        if(memo.count(pos)) return memo[pos];
        
        bool resu = false;
        for(int i = pos; i<s.size(); i++){
            string word = s.substr(pos, i-pos+1);
            if(dict.count(word)){
                resu = dp(s, i+1, dict);
            }
            if(resu) break;
        }

        memo[pos] = resu;
        return memo[pos];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return dp(s, 0, dict);
    }
};