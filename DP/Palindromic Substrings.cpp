class Solution {
public:

    map<pair<int,int>,int>memo;
    int dp(string &s, int start, int end){
        if(memo.count({start,end})) return memo[{start,end}];
        if(end-start+1 == 1) return 1;
        if(end-start+1 == 2 && s[start] == s[end]) return 1;
        if(s[start] != s[end]) return 0;

        memo[{start, end}] = dp(s, start+1, end-1);
        return memo[{start,end}];
    }
    int countSubstrings(string s) {
        int suma = 0;
        for(int i = 0; i<s.size(); i++){
            for(int j = i;j<s.size(); j++){
                suma+=dp(s, i, j);
            }
        }
        return suma;
    }
};