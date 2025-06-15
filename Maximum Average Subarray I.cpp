class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size()<k){
            return 0;
        }
        double inicial=0;
        for(int i = 0;i<k;i++){
            inicial+=nums[i];
        }
        double maximo = inicial/k;
        int inicio = 0;
        int front =k-1;
        while(front+1<nums.size()){
            inicial-=nums[inicio];
            inicial+=nums[front+1];
            maximo = max(maximo,inicial/k);
            front++;
            inicio++;
        }
        cout<<maximo<<endl; 
        return maximo;
    }
};