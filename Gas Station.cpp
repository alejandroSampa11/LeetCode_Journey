class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasTotal = 0;
        int costTotal = 0;
        for(int i= 0;i<gas.size();i++){
            gasTotal+=gas[i];
            costTotal+=cost[i];
        }
        if(gasTotal<costTotal){
            return -1;
        }
        int gaso = 0;
        int inicio=0;
        for(int i =0;i<gas.size();i++){
            gaso+= gas[i]- cost[i];
            if(gaso<0){
                gaso=0;
                inicio=i+1;
            }
        }
        return inicio;
    }
};