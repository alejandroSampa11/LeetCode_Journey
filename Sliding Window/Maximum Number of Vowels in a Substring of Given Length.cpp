class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int start = 0;
        int maxVowel = 0;
        int temp = 0;
        for (int end = 0; end < n; end++) {
            if (s[end] == 'a' || s[end] == 'e' || s[end] == 'i' ||
                s[end] == 'o' || s[end] == 'u') {
                temp++;
            }
            if (end - start + 1 >= k) {
                maxVowel = max(maxVowel, temp);
                if (s[start] == 'a' || s[start] == 'e' || s[start] == 'i' ||
                    s[start] == 'o' || s[start] == 'u') {
                    temp--;
                }
                start++;
            }
        }
        return maxVowel;
    }
};