class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int mini = INT_MAX;
        int whites = 0;
        for(int i = 0; i<blocks.size();i++){
            if(blocks[i] == 'W') whites++;
            
            if(i >= k-1){
                // cout<<whites<<endl;
                mini = min(whites, mini);
                if(blocks[i-k+1] == 'W'){
                    whites--;
                }
            }
        }
        return mini;
    }
};