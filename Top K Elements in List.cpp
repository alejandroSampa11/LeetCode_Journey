class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>freq;
        map<int,int>freq2;
        vector<int> res;
        vector<pair<int,int>> pares;
        for(int i = 0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(const auto& [key, value] : freq){
            pair<int,int>par1(value,key);
            pares.push_back(par1);
        }

        sort(pares.rbegin(),pares.rend());

        for(int i = 0;i<k;i++){
            res.push_back(pares[i].second);
        }

        return res;
    }
};
