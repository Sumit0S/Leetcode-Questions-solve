class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int maxi=0;

        for(int i=0; i<nums.size()-1; i++)
        {
            int curr=i+nums[i];
            maxi=max(curr,maxi);
            if(i>=maxi){
                return false;
            }
        }    

        return true;
    }
};