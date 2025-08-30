class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
         sort(nums.begin(),nums.end());

         int j=0;
         for(int i=0; i<nums.size(); i++){
            if(nums[j]!=nums[i] and j+1<=i){
                swap(nums[j+1],nums[i]);
                j+=1;
            }
         }

         return j+1; 
    }
};