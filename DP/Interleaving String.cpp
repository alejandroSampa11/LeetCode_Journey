class Solution {
public:

    map<pair<int, int>,int> memo;
    bool dp(string& s1, string& s2, string&s3, int pos1, int pos2){
        if(memo.count({pos1, pos2})) return memo[{pos1, pos2}];
        if(pos1+pos2 == s3.size()) return true;

        bool resu = false;
        if(pos1 < s1.size() && s3[pos1+pos2] == s1[pos1]){
            resu = dp(s1, s2, s3, pos1+1, pos2);
        }
        if(!resu && pos2 < s2.size() && s3[pos1+pos2] == s2[pos2]){
            return dp(s1, s2, s3, pos1, pos2+1);
        }

        return memo[{pos1, pos2}] = resu;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+ s2.size() != s3.size()) return false;
        return dp(s1,s2,s3,0,0);
    }
};