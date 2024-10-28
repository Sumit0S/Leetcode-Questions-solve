class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0,prev=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                cnt=max(cnt,prev);
                prev=0;
            }
            else{
                prev+=1;
            }
        }
        cnt=max(cnt,prev);
        return cnt;
    }
};