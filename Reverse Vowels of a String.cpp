class Solution {
public:
    string reverseVowels(string s) {
        vector<char>letras;
        for(auto& x : s){
            if( x == 'a' || x == 'A' || x == 'e' || x == 'E' || x == 'i' || x == 'I' || x == 'o' || x == 'O' || x == 'u' || x == 'U'){
                letras.insert(letras.begin(),x);
            }
        }
        
        int j = 0;
        for(int i = 0;i<s.size();i++){
            if( s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U'){
                s[i]=letras[j];
                j++;
            }
        }

        return s;
    }
};