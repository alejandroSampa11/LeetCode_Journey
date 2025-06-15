class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        vector<vector<int>> resu(img.size(), vector<int>(img[0].size(), 0));
        for(int i = 0;i<img.size();i++){
            for(int j = 0;j<img[i].size();j++){
                int suma = img[i][j];
                int contador = 1;
                if(i-1 >= 0){
                    suma+=img[i-1][j];
                    contador++;
                }
                if(i+1 < img.size()){
                    suma+=img[i+1][j];
                    contador++;
                }
                if(j-1 >= 0){
                    suma+=img[i][j-1];
                    contador++;
                }
                if(j+1 < img[i].size()){
                    suma+=img[i][j+1];
                    contador++;
                }
                if(i-1 >=0 && j-1 >= 0 ){
                    suma+=img[i-1][j-1];
                    contador++;
                }
                if(i+1 < img.size() && j+1 < img[i].size() ){
                    suma+=img[i+1][j+1];
                    contador++;
                }
                if(i+1 < img.size() && j-1 >= 0 ){
                    suma+=img[i+1][j-1];
                    contador++;
                }   
                if(i-1 >= 0 && j+1 <img[i].size() ){
                    suma+=img[i-1][j+1];
                    contador++;
                }
                resu[i][j] = suma/contador;
            }
        }
        return resu;
    }
};