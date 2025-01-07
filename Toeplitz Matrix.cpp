class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int x = matrix[0].size(); // COLUMNAS
        int y = matrix.size(); //FILAS

        for(int i = 0;i < y;i++){
            int fila = i+1;
            int columna = 1;
            while(fila<y && columna <x){
                // cout<<matrix[fila-1][columna-1]<<" "<<matrix[fila][columna]<<endl;
                if(matrix[fila-1][columna-1] != matrix[fila][columna]){
                    return false;
                }
                fila++;
                columna++;
            }
        }
        for(int i = 1;i < x;i++){
            int fila2 = 1;
            int columna2 = i+1;
            while(fila2<y && columna2 <x){
                // cout<<matrix[fila2-1][columna2-1]<<" "<<matrix[fila2][columna2]<<endl;
                if(matrix[fila2-1][columna2-1] != matrix[fila2][columna2]){
                    return false;
                }
                fila2++;
                columna2++;
            }
        }

        return true;
    }
};