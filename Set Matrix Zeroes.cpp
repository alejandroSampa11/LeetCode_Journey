class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> ceros;

        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[i].size();j++){
                if(matrix[i][j] == 0){
                    ceros.push_back({i,j});
                }
            }
        }
        for(pair<int,int> x : ceros){
            cout<<x.first<<" "<<x.second<<endl;
            for(int i = 0; i < matrix[0].size();i++){
                matrix[x.first][i] = 0;
            }
            for(int i = 0; i < matrix.size();i++){
                matrix[i][x.second] = 0;
            }
        }
    }
};