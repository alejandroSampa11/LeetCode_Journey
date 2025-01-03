class Solution {
public:

    bool canJump(vector<int>& nums) {
        vector<bool>resu(nums.size(),false);
        resu[0] = true;

        for(int i = 0;i<nums.size();i++){
            if(nums[i]>0 && resu[i]==true){
                for(int j = 1;j<=nums[i];j++){
                    if(j+i<nums.size()){
                        resu[j+i] = true;
                    }
                }
            }
        }

        for(int j = 0;j<resu.size();j++){
                cout<<resu[j]<<endl;
        }

        return resu[resu.size()-1];
        
    }
};