class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int left = 0;
        int right = (rows*cols) - 1;

        while(left<=right){
            int mid = left + (right-left)/2;
            int midValue = matrix[mid/cols][mid%cols];
            if(target == midValue) return true;
            if(target>midValue) left = mid+1;
            if(target<midValue) right = mid-1;
        }

        return false;
    }
};