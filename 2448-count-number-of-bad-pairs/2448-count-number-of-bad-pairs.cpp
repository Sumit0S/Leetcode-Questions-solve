class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans=0;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            ans+=mp[i-nums[i]]++;
        }
        long long int n=nums.size();
        return ((n*(n-1))/2)-ans;
    }
};