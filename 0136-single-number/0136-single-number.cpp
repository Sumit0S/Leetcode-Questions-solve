class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int el=0;
           for(int i=0; i<nums.size(); i++){
            el^=nums[i];
           } 
           return el;
    }
};