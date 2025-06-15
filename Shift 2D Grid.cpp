class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int>all;
        for(vector<int> x : grid){
            for(int y : x){
                all.push_back(y);
            }
        }

        int contador = 0;
        int sobra = k % all.size();
        int cantidad = sobra;

        //ROTAMOS EL VECTOR
        rotate(all.rbegin(),all.rbegin()+sobra,all.rend());
        

        vector<vector<int>> resu;
        vector<int>row;
        for(int i = 0;i<all.size();i++){
            if(contador<grid[0].size()){
                row.push_back(all[i]);
                contador++;
            }else{
                resu.push_back(row);
                row.clear();
                contador = 0;
                row.push_back(all[i]);
                contador++;
            }
        }
        resu.push_back(row);
        return resu;
    }
};