class Solution {
    public:
        int lengthOfLastWord(string s) {
            int lon = 0;
            bool flag = false;
            for(int i = s.size()-1;i>=0;i--){
                if(s[i] == ' ' && flag){
                    return lon;
                }else if(s[i] == ' '){
                    continue;
                }else if(s[i] != ' '){
                    lon++;
                    flag = true;
                } 
            }
            return lon;
        }
    };