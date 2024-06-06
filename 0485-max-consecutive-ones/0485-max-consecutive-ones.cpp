class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int ones=0;
        for(int i=0; i<nums.size(); i++){
            int curr=0;
            if(nums[i]==1){
                for(int j=i; j<nums.size(); j++){
                    if(nums[j]!=1){
                        break;
                    }
                    curr+=1;
                }
            }
            ones = max(curr,ones);
        }
        return ones; 
    }
};