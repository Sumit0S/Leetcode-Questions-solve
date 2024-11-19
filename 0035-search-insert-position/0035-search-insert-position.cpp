class Solution {
public:
    int searchInsert(vector<int>& arr, int k) {
        int low=0;
        int high=arr.size()-1;
        int ans=arr.size();
        while(low<=high){
            int mid=low+(high-low)/2;

            if(arr[mid]>=k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};