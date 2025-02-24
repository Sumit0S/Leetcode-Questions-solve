class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(),nums.end());

        for(int i=0; i<nums.size(); i++){
            mp.insert(nums[i]);
        }
        
        
        int ans=0;
        for(auto it:mp){
            int curr_ele=it;
            int len=1;
            if(mp.find(curr_ele-1)!=mp.end()){
                continue;
            }
            else{  
                while(mp.find(curr_ele+1)!=mp.end())
                {
                    curr_ele+=1;
                    len+=1;
                }
            }
            ans=max(ans,len);
        }
        return ans;
    }
};