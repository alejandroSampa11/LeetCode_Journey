class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
         map<int,int>bill;
         for(int x : bills){
            if(x ==5){
                bill[x]++;
            }
            if(x==10){
                if(bill[5]>0){
                    bill[5]--;
                    bill[10]++;
                }else{
                    return false;
                }
            }
            if(x==20){
                if(bill[5]>0 && bill[10]>0){
                    bill[5]--;
                    bill[10]--;
                    bill[20]++;
                }else if(bill[5]>=3){
                    bill[5]-=3;
                }else{
                    return false;
                }
                    
            }
         }
        return true;
    }
};