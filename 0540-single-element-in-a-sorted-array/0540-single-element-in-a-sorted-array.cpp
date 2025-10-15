class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int low=0;
        int n = nums.size();
        int high=nums.size()-1;
        
        if(nums.size()==1 or nums[low]!=nums[low+1]){
            return nums[low];
        }
        if(nums[high]!=nums[high-1]){
            return nums[high];
        }

        while(low<=high){
            long mid=low+(high-low)/2;

            if (mid > 0 && mid < n - 1 && nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            cout<<mid<<" ";
            if(nums[mid]==nums[mid-1]){
                long val=mid-low+1;
                if(val%2==0){
                    low=mid+1;
                }
                else{
                    high=mid-2;
                }
            }
            else{
                long val=high-mid+1;
                if(val%2==0){
                    high=mid-1;
                }
                else{
                    low=mid+2;
                }                
            }
        }
        return -1;    
    }
};