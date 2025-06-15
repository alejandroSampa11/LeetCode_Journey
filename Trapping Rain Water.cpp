class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
       for(int i = 0;i<height.size();i++){
        int maxLeft = 0;
        int maxRight = 0;

        for(int left = 0;left<i;left++){
            maxLeft = max(maxLeft,height[left]);
        }
        for(int right = i+1;right<height.size();right++){
            maxRight = max(maxRight,height[right]);
        }
        if(min(maxLeft,maxRight)-height[i]>0){
            total+=min(maxLeft,maxRight)-height[i];
        }
       }
       return total; 
    }
};
