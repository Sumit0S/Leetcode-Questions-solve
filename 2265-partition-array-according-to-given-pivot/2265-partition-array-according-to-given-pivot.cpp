class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot)
    {
        vector<int> ans(nums.size());
        int j=0;
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<pivot){
                ans[j]=nums[i];
                j++;
            }
            if(nums[i]==pivot){
                cnt++;
            }
        }

        for(int i=0; i<cnt; i++){
            ans[j]=pivot;
            j++;
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>pivot){
                ans[j]=nums[i];
                j++;
            }
        }
        return ans;
    }
};