class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    bool canSortArray(vector<int>& nums) {


        for(int i=0; i<nums.size(); i++){

            if(i+1<nums.size() and countSetBits(nums[i])==countSetBits(nums[i+1]) and nums[i]>nums[i+1]){
                swap(nums[i],nums[i+1]);   
                i=0; 
            }

            else if(i>0 and countSetBits(nums[i])==countSetBits(nums[i-1]) and nums[i]<nums[i-1]){
                swap(nums[i],nums[i-1]); 
                    i=0;   
            }

        }

        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]>nums[i]){
                return false;
            }
        }
        return true;
    }
};