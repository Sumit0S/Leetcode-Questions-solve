class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int el;
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            if(cnt==0){
                el=nums[i];
                cnt=1;
            }
            else if(el==nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
            // if(el!=nums[i] and cnt>0){
            //     cnt--;
            // }

        }
        // cout<<el;
        int cnt1=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==el){
                cnt1++;
            }
            
        }

        if(cnt1>(nums.size()/2)){
            return el;
        }
        return -1;;
    }
};