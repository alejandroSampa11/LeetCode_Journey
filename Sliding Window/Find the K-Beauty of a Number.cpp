class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string number = to_string(num);
        int resu = 0;
        string window = "";
        for(int i = 0;i<number.size();i++){
            window+=number[i];
            if(i >= k-1){
                int numerito = stoi(window);
                if(numerito != 0 && num % numerito == 0){
                    resu++;
                }
                window.erase(0,1);
            }
        }
        return resu;
    }
};