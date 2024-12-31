class Solution {
public:
    bool isPalindrome(string s) {
        string original = "";
        for(const auto& caracter : s){
            if(!isalnum(caracter)){
                continue;
            }
            original+=tolower(caracter);
        }
        cout<<original<<endl;
        string copia = original;
        reverse(copia.begin(),copia.end());
        cout<<copia<<endl;
        if(copia==original){
            return true;
        }
        return false;
    }
};
