class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for(int x : arr){
            sum+=x;
        }
        if(sum%3 != 0){
            return false;
        }
        int obj = sum/3;
        int cont = 0;
        int temp = 0;
        for(int x : arr){
            temp+=x;
            if(temp == obj){
                cont++;
                temp= 0;
            }
        }
        if(cont >= 3) return true;
        return false;
        
    }
};