class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int temp = 0;
        int start = 0;
        int resu = 0;
        unordered_map<char,int> mp;
        for(int end = 0; end<s.size(); end++){
            mp[s[end]]++;
            while(mp[s[end]]>1){
                mp[s[start]]--;
                start++;
            }
            resu = max(resu, end-start+1);
        }
        return resu;
    }
};
