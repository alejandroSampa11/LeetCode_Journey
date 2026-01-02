class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int start = 0;
        int resu = 0;
        for(int end = 0; end<s.size();end++){
            mp[s[end]]++;
            while(mp['a']>0 && mp['b']>0 && mp['c']>0){
                resu+= s.size()-end;
                mp[s[start]]--;
                start++;
            }
        }
        return resu;
    }
};