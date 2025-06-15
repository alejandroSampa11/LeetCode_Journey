class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1){
            return s;
        }
        string max = ""; 
    
        int pivote = 0;
        while(pivote<s.size()-1){
            string temp = string(1, s[pivote]);
            int j = 1;
            while(pivote-j>=0 && pivote+j){
                if(s[pivote-j] == s[pivote+j]){
                    temp = string(1,s[pivote-j]) + temp +string(1,s[pivote+j]);
                    j++;
                }else{
                    break;
                }
            }
            if(temp.size()>max.size()){
                max = temp;
            }

            if(s[pivote]==s[pivote+1]){
                temp = string(1,s[pivote]) + string(1,s[pivote+1]);
                int y = 1;
                while(pivote-y>=0 && pivote+1+y){
                    if(s[pivote-y] == s[pivote+1+y]){
                        temp = string(1,s[pivote-y]) + temp +string(1,s[pivote+1+y]);
                        y++;
                    }else{
                        break;
                    }
                }
                if(temp.size()>max.size()){
                    max = temp;
                }
            }
            pivote++;
        }
        return max;
    }
};