class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        int val=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                count++;
            }
            if(nums[i]!=0){
                nums[val++]=nums[i];
            }
        }
        int ss=nums.size()-1;
        for(int i=0; i<count; i++){
            nums[ss-i]=0;
        }
    }
};