class Solution {
public:

    string encode(vector<string>& strs) {
        string code = "";
        for(const auto& palabra : strs){
            code+=to_string(palabra.size());
            code+="#";
            code+=palabra;
        }
        cout<<code<<endl;
        return code;
    }

    vector<string> decode(string s) {
        vector<string> resu;
        int i = 0;
        while(i<s.size()){
            int fin =i;
            while(s[fin]!='#'){
                fin++;
            }
            int longitud = stoi(s.substr(i,fin-i));
            string cadena = s.substr(fin+1,longitud);
            resu.push_back(cadena);
            i = fin+longitud+1; 
        }
        return resu;
    }
};
