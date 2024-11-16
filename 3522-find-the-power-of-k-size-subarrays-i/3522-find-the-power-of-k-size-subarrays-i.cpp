class Solution {
public:

    bool is_sor(vector<int>& nums,int i,int k){
        for(int j=i+1; j<k; j++){
            if(nums[j-1]>=nums[j]){
                return false;
            }            
        }
        
        return true;
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans(nums.size()-k+1,-1);
        if(nums.size()<k){
            return ans;
        }
        if(k==1){
            return nums;
        }
        for(int i=0; i<nums.size()-k+1; i++){
            if(is_sor(nums,i,i+k)){
                int is_m=nums[i];
                for(int j=i+1; j<i+k; j++){
                    if(nums[j]-is_m!=1){
                        is_m=-1;
                        break;
                    }
                    is_m=max(is_m,nums[j]);
                }
                ans[i]=is_m;
            }
            cout<<endl;
        }
        return ans;
    }
};