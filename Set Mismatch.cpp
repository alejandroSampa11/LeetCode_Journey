class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int numeroRepetido = 0;
        sort(nums.begin(),nums.end());
        int contador=1;
        if(contador==nums[0]){
            contador++;
        }
        for(int i = 1; i < nums.size();i++){
            if(nums[i-1]==nums[i]){
                numeroRepetido=nums[i];
            }
            if(contador==nums[i]){
                contador++;
            }
        }

        cout<<numeroRepetido<<endl;
        cout<<contador<<endl;
        return {numeroRepetido, contador};
    }
};