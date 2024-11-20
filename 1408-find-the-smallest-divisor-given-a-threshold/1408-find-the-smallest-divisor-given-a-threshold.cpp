class Solution {
public:

    int findmin(vector<int> &nums){
        int mini=INT_MAX;
        for(auto it:nums){
            mini=min(mini,it);
        }
        return mini;
    }

    int findmax(vector<int> &nums){
        int maxi=INT_MIN;
        for(auto it:nums){
            maxi=max(maxi,it);
        }
        return maxi;       
    }
    bool is_s(vector<int>& nums, int threshold,int mid){
        int val=0;
        for(int i=0; i<nums.size(); i++){
            val+=ceil((double)nums[i]/(double)mid);
        }
        return threshold>=val;
    }

    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int low=1;
        int high=findmax(nums);

        while(low<=high){
            int mid=low+(high-low)/2;
            if(is_s(nums,threshold,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        } 
        return low; 
    }
};