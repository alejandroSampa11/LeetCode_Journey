class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int cont = 0;
        vector<int> prefix (arr.size()+1, 0);
        for (int i = 0; i < arr.size(); i++) {
            cont += arr[i];
            prefix[i+1] = cont;
        }
        int resu = 0;
        for (int start = 1; start < prefix.size(); start++) {
            for (int end = start; end < prefix.size(); end++) {
                if (((end - start + 1) % 2) != 0) {
                   resu+= prefix[end] - prefix[start-1];
                }
            }
        }
        return resu;
    }
};