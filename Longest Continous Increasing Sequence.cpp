class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int contador = 1;
        int maximo = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                contador++;
            }else{
                maximo = max(maximo,contador);
                contador=1;
            }
        }
        maximo = max(maximo,contador);
        return maximo;
    }
};