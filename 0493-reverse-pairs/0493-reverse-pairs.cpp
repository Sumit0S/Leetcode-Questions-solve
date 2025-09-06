class Solution {
public:

    int cnt=0;
    void countPairs(vector<int>& nums,int low,int mid,int high){
        int right=mid+1;
        int temp=0;
        for(int i=low; i<=mid; i++){
            while(right <=high and (long long)nums[i] > 2LL * nums[right]){
                right++;
            }
            cnt+=(right - (mid + 1));
        }
    }
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }
    
    void Divide_cn(vector<int>& nums,int low,int high)
    {
        if(low>=high){
            return;
        }
        int mid=(low+high)/2;
        Divide_cn(nums,low,mid);
        Divide_cn(nums,mid+1,high);
        countPairs(nums, low, mid, high);
        merge(nums,low,mid,high);
    }
    int reversePairs(vector<int>& nums) 
    {
        
        int n=nums.size();
        Divide_cn(nums,0,n-1);
        for(auto it:nums){
            cout<<it<<" ";
        }
        return cnt;
    }
};