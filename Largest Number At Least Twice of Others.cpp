class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int> numCopia = nums;
        sort(numCopia.begin(),numCopia.end());
        int numMayor = numCopia[numCopia.size()-1];
        int mitad = numMayor/2;
        int indice = -1;
        for(int i = nums.size()-1;i>=0;i--){
            if(nums[i] == numMayor){
                indice = i;
                continue;
            }
            if(nums[i]>mitad){
                indice = -1;
                break;
            }
        }
        return indice; 
    }
};