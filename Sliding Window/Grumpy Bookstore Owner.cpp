class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int satisfied = 0;
        for(int i = 0; i<n; i++){
            if(!grumpy[i]){
                satisfied+=customers[i];
            }
        }

        int start = 0;
        int temp = satisfied;
        for(int end = 0; end<n; end++){
            if(grumpy[end]){
                temp+=customers[end];
            }
            if(end-start+1>= minutes){
                satisfied = max(temp, satisfied);
                if(grumpy[start]){
                    temp-=customers[start];
                }
                start++;
            }
        }
        return satisfied;
    }
};