class Solution {
public:

    void rellenar(vector<vector<int>>& image, int sr, int sc, int color, int original){
        if(sr<0 || sr >= image.size() || sc<0 || sc >= image[0].size()){
            return;
        }
        if(image[sr][sc]!= original || image[sr][sc] == color){
            return;
        }
        image[sr][sc] = color;
        rellenar(image, sr+1, sc, color, original);
        rellenar(image, sr-1, sc, color, original);
        rellenar(image, sr, sc+1, color, original);
        rellenar(image, sr, sc-1, color, original);
        return; 
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        rellenar(image, sr,sc,color, image[sr][sc]);
        return image;
    }
};