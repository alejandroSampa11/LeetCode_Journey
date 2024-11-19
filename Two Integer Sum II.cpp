class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> resu;
        for(int i = 0;i<numbers.size();i++){
            for(int j = i+1;j<numbers.size();j++){
                if((numbers[i]+numbers[j]) == target){
                    resu.insert(resu.end(),{i+1,j+1});
                    return resu;
                }
            }
        }
        return resu;
    }
};
