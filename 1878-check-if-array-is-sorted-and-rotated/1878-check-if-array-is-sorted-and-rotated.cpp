class Solution {
public:
    bool check(vector<int>& nums) {
        int br=nums.size()-1;
        int last=0;
        int cnt=0;
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i]>nums[i+1])
            {
                last=nums[i];
                br=i+1;
                cnt+=1;
            }
        }
        cout<<last<<" "<<br<<endl;
        if(cnt>1){
            return false;
        }

        for(int i=br; i<nums.size()-1; i++)
        {
            if(nums[i]>nums[i+1] or nums[i]>nums[0] or nums[i+1]>nums[0]){
                return false;
            }
        }
        if(nums[br]>nums[0] and cnt!=0){
            return false;
        }
        return true;
    }
};