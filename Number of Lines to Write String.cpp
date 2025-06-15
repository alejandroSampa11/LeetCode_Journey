class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        map<char,int>letras;
        char inicio = 'a'; 
        for(auto& x : widths){
            letras[inicio]=x;
            inicio++;
        }
        int total = 0;
        int renglones = 1;
        string letraUsadas="";
        for(auto& x: s){
            total+=letras[x];
            letraUsadas+=x;
            if(total>100){
                renglones++;
                total=letras[x];
                letraUsadas=x;
            }   
        }
        
        vector<int>resu = {renglones,total};
        return resu;
    }
};