class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size()-1;
        int resu = 0;
        while(left <= right){
            int mid = left + (right-left)/2;
            cout<<arr[mid]<<endl;
            if(arr[mid-1]< arr[mid] && arr[mid] > arr[mid+1]){
                resu = mid;
                break;
            }
            if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]){
                left = mid;
            }
            if(arr[mid-1]>arr[mid] && arr[mid]>arr[mid+1]){
                right = mid;
            }
        }
        return resu;
    }
};