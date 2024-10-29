class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        long int ans=nums[0];
        long int sum=0;
        // if(nums.size()==1){
        //     return nums[0];
        // }
        
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(sum<0){
                ans=max(ans,sum);
                sum=0;
            }

            else{
                ans=max(ans,sum);
            }
        }     
        return ans;
    }
};