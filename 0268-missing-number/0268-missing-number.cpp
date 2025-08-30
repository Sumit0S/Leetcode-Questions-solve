class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();

        int ans =(n*(n+1))/2;

        cout<<ans;
        int cnt=0;

        for(auto it:nums){
            cnt+=it;
        }

        return ans-cnt;
    }
};