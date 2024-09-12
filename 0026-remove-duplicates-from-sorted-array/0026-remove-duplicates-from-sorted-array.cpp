class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        if(nums.size()<2){
            return nums.size();
        }
        int j=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[j]==nums[i]){
                continue;
            }
            else{
                j++;
                nums[j]=nums[i];
                // j+=1;
            }
        }
        // if(nums[nums.size()-1]!=nums[nums.size()-2]){
        //         nums[j]=nums[nums.size()-1];
        //         j+=1;
        // }
        return j+1;    
    }
};