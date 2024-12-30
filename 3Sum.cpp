class Solution {
public:

    bool existeArray(vector<vector<int>>& padre, vector<int> hijo ){
        for(const auto& peq : padre){
            if(peq == hijo){
                return true;
            }
        }
        return false;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> resu;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++){
            int izq = i+1;
            int der = nums.size()-1;
            while(izq<der){
                int suma = nums[i]+nums[izq]+nums[der];
                if(suma<0){
                    izq++;
                }else if(suma>0){
                    der--;
                }else{  
                    vector<int>trio;
                    trio.push_back(nums[i]);
                    trio.push_back(nums[izq]);
                    trio.push_back(nums[der]);
                    if(!existeArray(resu,trio)){
                        resu.push_back(trio);
                    }
                    izq++;
                    der--;
                }
            }
        }
        return resu;
    }
};
