class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int n=nums.size();
        long int sum=0;
        unordered_map<int,int> mp;
        vector<int> v(2);
        for(int r=0; r<n; r++){
            sum=target-nums[r];
            if(mp.find(sum)!=mp.end()){
                v[0]=mp[sum];
                v[1]=r;
            }
            mp[nums[r]]=r;
        }
        return v;
    }
};