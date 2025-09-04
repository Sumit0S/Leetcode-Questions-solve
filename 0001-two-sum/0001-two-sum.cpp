class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> st;

        for(int i=0; i<nums.size(); i++){
            int find_=target-nums[i];
            if(st.find(find_)!=st.end())
            {
                return {st[find_],i};
            }
            st[nums[i]]=i;
        }

        return {0,0};
    }
};