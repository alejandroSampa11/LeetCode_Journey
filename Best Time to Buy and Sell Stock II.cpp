class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int acumulado = 0;
        int accion = 0;
        vector<int> resu;
        for(int i = 1;i<prices.size();i++){
            if(prices[i]-prices[i-1]>0){
                accion+=prices[i]-prices[i-1];
            }else{
                // resu.push_back(accion);
                acumulado+=accion;
                accion = 0;
            }
        }
        // resu.push_back(accion);
        acumulado+=accion;

        // for(int i = 0;i<resu.size();i++){
        //     cout<<resu[i]<<endl;
        // }

        return acumulado;
    }
};