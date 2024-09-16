class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> ans;
        unordered_map<int,int> mpp;
        
        for(int i=0; i<nums.size(); i++){
            int is_ans=target-nums[i]; 
            if(mpp.find(is_ans)!=mpp.end()){
                    ans.push_back(i);
                    ans.push_back(mpp[is_ans]);
                    break;
            }
            mpp[nums[i]]=i;
        }
   
        return ans;
    }
};