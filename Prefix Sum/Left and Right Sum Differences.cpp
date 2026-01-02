class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> first(nums.size() + 1, 0);
        vector<int> second(nums.size() + 1, 0);

        for (int i = 0; i < nums.size(); i++) {
            first[i + 1] = first[i] + nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            second[nums.size() - 1 - i] = first[first.size() - 1] - first[nums.size() - 1 - i];
        }
        vector<int> resu;
        for(int i = 0; i<first.size()-1; i++){
            resu.push_back(abs(first[i]-second[i+1]));
        }

        return resu;
    }
};