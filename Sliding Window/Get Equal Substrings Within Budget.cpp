class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int start = 0;
        int n = s.size();
        int valor = 0;
        int maxLength = 0;
        for (int end = 0; end < n; end++) {
            valor += abs(s[end] - t[end]);
            while(valor>maxCost){
                valor-=abs(s[start] - t[start]);
                start++;
            }
            maxLength = max(maxLength, end-start+1);
        }
        return maxLength;
    }
};