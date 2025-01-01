class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        map<char,int>letras;
        for(auto& x: licensePlate){
            x = tolower(x);
            if(x < 'a' || x > 'z'){
                continue;
            }
            letras[x]++;
        }

        string palabraR = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
        for(int i = 0;i<words.size();i++){
            map<char,int>letrasA;
            string palabraTemp =""; 
            for(int j = 0;j<words[i].size();j++){
                letrasA[words[i][j]]++;
                palabraTemp+=words[i][j];
            }
            bool flag = true;
            for (const auto& [key, value] : letras) {
                if(letrasA[key]<value){
                    flag = false;
                    break;
                }
            }
            if(flag){
                if(palabraTemp.size()<palabraR.size()){
                    palabraR = palabraTemp;
                }
            }
        }

        return palabraR;
    }
};