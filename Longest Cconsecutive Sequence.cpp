class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return 1;
        }
        sort(nums.begin(),nums.end());
        for(auto& x : nums){
            cout<<x<<endl;
        }
        int maximo = 1;
        int contador = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]-1 == nums[i-1]){
                contador++;
                maximo = max(maximo,contador);
            }else if( nums[i] == nums[i-1]){
                continue;
            }else{
                contador = 1;
            }
        } 
        return maximo;
    }
};