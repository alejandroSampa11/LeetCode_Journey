class Solution {
    public:
        string reverseWords(string s) {
            vector<string>palabras;
            string word = "";
            for(int i = 0;i<s.size();i++){
                if(s[i] == ' '){
                    if(word==""){
                        continue;
                    }
                    palabras.push_back(word);
                    word="";
                }else if(i == s.size()-1){
                    word+=s[i];
                    if(word==""){
                        continue;
                    }
                    palabras.push_back(word);
                }else{
                    word+=s[i];
                }
    
            }
    
            reverse(palabras.begin(), palabras.end());
            string resu = "";
            for(int i = 0;i<palabras.size()-1;i++){
                resu+=palabras[i];
                resu+=" ";
            }
            resu+=palabras[palabras.size()-1];
    
            return resu;
        }
    };