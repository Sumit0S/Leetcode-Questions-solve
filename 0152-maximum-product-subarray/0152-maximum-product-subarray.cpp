class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int ans=nums[0];
        for(int i=0; i<nums.size(); i++){
            int temp=nums[i];
            for(int j=i+1; j<nums.size(); j++){
                ans=max(ans,temp);
                temp=temp*nums[j];
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};