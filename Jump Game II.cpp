class Solution {
public:

    int jump(vector<int>& nums) {
        vector<int>suma(nums.size(),INT_MAX);
        suma[0] = 0;

        for(int i = 0;i<suma.size();i++){
            for(int j = 1;j<=nums[i];j++){
                if(j+i<nums.size()){
                    suma[j+i] = min(suma[j+i],suma[i]+1);
                }
            }
        }

        // for(int i = 0;i<suma.size();i++){
        //     cout<<suma[i]<<endl;
        // }
        
        return suma[suma.size()-1];
    }
};