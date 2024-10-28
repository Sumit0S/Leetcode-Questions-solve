class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int j=1;

        if(nums.size()<=1){
            return 1;
        }

        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]!=nums[i]){
                nums[j]=nums[i];
                j++;
            }
        }

        // if(nums[j]!=nums[nums.size()-1]){
        //     nums[j]=nums[nums.size()-1];
        //     j++;
        // }
        cout<<j;
        return j;
    }
};