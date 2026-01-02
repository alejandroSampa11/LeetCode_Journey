class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;
        int start = 0;
        int maxi = INT_MIN;
        for(int i = 0; i<s.size(); i++){
            mp[s[i]]++;
            while(mp[s[i]]>2){
                mp[s[start]]--;
                start++;
            }
            maxi = max(maxi, i-start+1);
        }
        return maxi;
    }
};