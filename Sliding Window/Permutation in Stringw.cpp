class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> need(26, 0);
        vector<int> have(26, 0);
        for (char x : s1) {
            need[x - 'a']++;
        }

        for (int i = 0; i < s2.size(); i++) {

            have[s2[i] - 'a']++;
            
            if (i >= s1.size()) {
                have[s2[i - s1.size()] - 'a']--;
            }

            if (i >= s1.size() - 1 && have == need) {
                return true;
            }
        }
        return false;
    }
};