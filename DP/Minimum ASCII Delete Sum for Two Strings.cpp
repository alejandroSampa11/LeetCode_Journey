class Solution {
public:

    map<pair<int,int>, int> memo;
    int dp(string& s1, string& s2, int pos1, int pos2){
        if(memo.count({pos1, pos2})) return memo[{pos1,pos2}];
        if(s1.size() == pos1 && s2.size() == pos2) return 0;
        if(pos1<s1.size() && pos2 == s2.size()){
            return (int)s1[pos1] + dp(s1, s2, pos1+1, pos2);
        };
        if(pos2<s2.size() && pos1 == s1.size()){
            return (int)s2[pos2] + dp(s1, s2, pos1, pos2+1);
        };

        int mini = INT_MAX;
        if(s1[pos1] == s2[pos2]){
            mini = dp(s1, s2, pos1+1, pos2+1);
        }else{
            int del1 = (int)s1[pos1] + dp(s1, s2, pos1+1, pos2);
            int del2 = (int)s2[pos2] + dp(s1, s2, pos1, pos2+1);
            mini = min(del1, del2);
        }

        return memo[{pos1, pos2}] = mini;
    }

    int minimumDeleteSum(string s1, string s2) {
        return dp(s1,s2,0,0);
    }
};