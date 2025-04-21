class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int maxi=0;

        if(nums.size()<=1)
        {
            return true;
        }

        for(int i=0; i<nums.size(); i++){
            int curr=i+nums[i];
            maxi=max(curr,maxi);
            if(maxi==nums.size()-1){
                return true;
            }
            if(nums[i]==0 and i>=maxi){
                return false;
            }
        }    

        return true;
    }
};