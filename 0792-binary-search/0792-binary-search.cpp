class Solution {
public:
    int search(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        int low=0;
        int high=nums.size()-1;
        int mid=low+((high-low)/2);

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target){
                return i;
            }
            else if(nums[i]<target){
                high=mid-1;
            }
            else if(nums[i]>target){
                low=mid+1;
            }
        }
        return -1;
    }
};