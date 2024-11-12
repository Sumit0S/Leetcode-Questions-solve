class Solution {
public:
    bool check(vector<int>& nums,int start,int k){
        for(int i=start; i<start+k-1; i++){
            if(nums[i]>=nums[i+1]){
                return false;
            }
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(nums.size()<2*k){
            return false;
        }
        if(k==1){
            return true;
        }
        for(int i=0; i<=nums.size()-2*k; i++){
            if(check(nums,i,k) and check(nums,i+k,k)){
                return true;
            }
        }
        return false;
    }
};