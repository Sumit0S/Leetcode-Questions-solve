class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int low=0;
        int high=arr.size()-1;

        while(low<=high){
            int mid=low + (high - low) / 2;
            if(arr[mid]==target){
                return true;
            }

        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }
            // left half sorted
            if(arr[low]<=arr[mid]){
                if(arr[low]<=target and target<=arr[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(arr[mid]<=target and target<=arr[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return false;       
    }
};