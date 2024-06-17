class Solution {
public:

    int calculate(vector<int> nums, int threshold,int num){
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            cnt=cnt+ceil((double)(nums[i]) / (double)(num));
        }
        return cnt;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low = 1, high = *max_element(nums.begin(), nums.end());

        while(low<=high){
            int mid=low+(high-low)/2;
            if(calculate(nums,threshold,mid)<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};