class Solution {
public:
    int reverse(int num){
        int ans=0;
        while(num>0){
            int l=num%10;
            ans=(ans*10)+l;
            num=num/10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int ans=0;
        int mod = 1e9+7;  
        unordered_map<int,int> mp;

        for(int i=0; i<nums.size(); i++){
            int rec=reverse(nums[i]);
            ans=(ans+mp[nums[i]-rec]++)%mod;
        }
        return ans;    
    }
};