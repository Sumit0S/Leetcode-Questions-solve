class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l=0;
        int cnt=0;
        int ans=0;
        for(int r=0; r<nums.size(); r++){
            if(nums[r]%2!=0){
                nums[r]=1;
            }
            else{
                nums[r]=0;
            }
        }
        return atMost(nums,k)-atMost(nums,k-1);
    }

private:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int l = 0, sum = 0, count = 0;
        
        for (int r = 0; r < nums.size(); ++r) {
            sum += nums[r];
            while (sum > k) {
                sum -= nums[l];
                l++;
            }
            count += (r - l + 1);
        }
        
        return count;
    }
};