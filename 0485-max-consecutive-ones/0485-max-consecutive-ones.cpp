class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int one=0;

        for(auto it:nums){
            if(it==1){
                one+=1;
                ans=max(one,ans);
            }
            else{
                one=0;
            }
        }
        return ans;    
    }
};