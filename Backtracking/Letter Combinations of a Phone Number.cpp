class Solution {
public:

    void backtracking(string digits, int itDigit, vector<string>& numbers, string path, vector<string>& resu){
        if(path.size() == digits.size()){
            resu.push_back(path);
            return;
        }
        for(int i = 0; i<numbers[digits[itDigit]-'0'].size(); i++){
            path.push_back(numbers[digits[itDigit]-'0'][i]);
            backtracking(digits, itDigit+1, numbers, path, resu);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> numbers = {"", "", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
        string path;
        vector<string> resu;
        backtracking(digits, 0, numbers, path, resu);

        return resu;
    }
};