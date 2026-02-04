class Solution {
public:
    map<pair<int, int>, int> memo;
    int dp(string& s, string& t, int posS, int posT) {
        if (memo.count({posS, posT}))
            return memo[{posS, posT}];
        if (posT == t.size())
            return 1;
        if (posS == s.size() && posT < t.size())
            return 0;

        int resu = 0;
        if (s[posS] == t[posT]) {
            resu += dp(s, t, posS + 1, posT + 1);
        }
        resu += dp(s, t, posS + 1, posT);

        memo[{posS, posT}] = resu;
        return memo[{posS, posT}];
    }

    int numDistinct(string s, string t) { return dp(s, t, 0, 0); }
};