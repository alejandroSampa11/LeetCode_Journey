class Solution {
    public:
        string convert(string s, int numRows) {
            if(numRows == 1){
                return s;
            }
            vector<string>resultados(numRows);
            int it = 0;
            bool dir = true;
            for(int i = 0;i<s.size();i++){
                if(dir){
                    resultados[it]+=s[i];
                    it++;
                    if(it==(numRows)-1){
                        dir = false;
                    }
                }else{
                    resultados[it]+=s[i];
                    it--;
                    if(it==0){
                        dir = true;
                    }
                }
    
            }
    
            string resu = "";
            for(auto& x : resultados){
                resu+=x;
            }
    
            return resu;
            
        }
    };