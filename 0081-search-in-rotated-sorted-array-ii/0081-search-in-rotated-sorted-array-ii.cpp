class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
      int low=0;
      int high=nums.size()-1;

      while(low<=high){
        int mid=low+((high-low)/2);
        // we found the element
        if (nums[mid] == target) return true;
        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low++,high--;
            continue;   
        }
        

        // left part is sorted
        if(nums[low]<=nums[mid]){
            if(nums[low]<=target and target<=nums[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        // right part sorted
        else{
            if(nums[mid]<=target and target<=nums[high]){
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