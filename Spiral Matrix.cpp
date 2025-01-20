class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>resu;
        int filas = matrix.size();
        int columnas = matrix[0].size();
        int finalC = columnas;
        int finalF = filas;
        int tempC = 0;
        int tempF = 0;
        int numColumnas = 0;
        int inicioF = 0;
        int inicioC=0;
        int numFilas = 0;

        while(filas>0 && columnas>0){
            //IDA DE COLUMNAS
            cout<<"IDA C"<<endl;
            for(int i = tempC;i<finalC;i++){
                resu.push_back(matrix[inicioC][i]);
                cout<<matrix[inicioC][i]<<endl;
                tempC++;
            }
            finalC--;
            filas--;
            tempC--;

            //IDA DE FILAS
            if(filas<1){
                break;
            }
            cout<<"IDA F"<<endl;
            for(int i = inicioF+1;i<finalF;i++){
                 resu.push_back(matrix[i][tempC]);
                cout<<matrix[i][tempC]<<endl;
                tempF++;
            }
            inicioF++;
            columnas--;
            if(columnas<1){
                break;
            }
            //REGRESO DE COLUMNAS
            cout<<"REGRESO C"<<endl;
            for(int i = tempC-1;i>=inicioC;i--){
                resu.push_back(matrix[tempF][i]);
                cout<<matrix[tempF][i]<<endl;
                tempC--;
            }
            inicioC++;
            filas--;

            if(filas<1){
                break;
            }
            //REGRESO DE FILAS
            cout<<"REGRESO F: "<<endl;
            for(int i = tempF-1;i>=inicioF;i--){
                resu.push_back(matrix[i][tempC]);
                cout<<matrix[i][tempC]<<endl;
                tempF--;
            }
            finalF--;
            columnas--;
            tempC++;
        }
        
        return resu;
    }
};