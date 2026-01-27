class Solution {
public:

    unordered_map<int, int> memo;
    unordered_set<string> dict;
    int dp(string& s, int pos){
        if(memo.count(pos)) return memo[pos];
        if(pos == s.size()) return 1;
        if(pos>s.size()) return 0;
        
        int resu = 0;
        for(int i = pos; i<pos+2 &&  i<s.size(); i++){
            string num = s.substr(pos,i-pos+1);
            if(num[0] == '0') continue;
            if(dict.count(num)){
                resu+=dp(s, i+1);
            }
        }

        memo[pos] = resu;
        return memo[pos];
    }

    int numDecodings(string s) {
        for(int i = 1; i<=26; i++){
            string num = to_string(i);
            dict.insert(to_string(i));
        }

        return dp(s, 0);
    }
};