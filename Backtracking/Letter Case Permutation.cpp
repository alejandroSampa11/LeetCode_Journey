class Solution {
public:
    void backtracking(string& s, vector<string>& resu, int start) {
        resu.push_back(s);

        for (int i = start; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9')continue;
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = tolower(s[i]);
                backtracking(s, resu, i+1);
                s[i] = toupper(s[i]);
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] = toupper(s[i]);
                backtracking(s, resu, i+1);
                s[i] = tolower(s[i]);
            }
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> resu;
        int start = 0;
        backtracking(s, resu, start);

        return resu;
    }
};