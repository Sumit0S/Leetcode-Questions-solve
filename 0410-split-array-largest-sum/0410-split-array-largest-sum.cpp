class Solution {
public:

    int calculateval(vector<int> &a, int maxSum) {
        int n = a.size(); //size of array.
        int partitions = 1;
        long long subarraySum = 0;

        for (int i = 0; i < n; i++) {
            if (subarraySum + a[i] <= maxSum) {
                //insert element to current subarray
                subarraySum += a[i];
            }
            else {
                //insert element to next subarray
                partitions++;
               
                subarraySum = a[i];
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int mini=0;
        int max2=0;
        
        for(int i=0; i<nums.size(); i++){
            mini=max(mini,nums[i]);
            max2+=nums[i];
        }

        int low=mini;
        int high=max2;
        int result = high;
        while(low<=high){
            int mid=(low+high)/2;
            int val=  calculateval(nums,mid);
            if(val<=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }
};