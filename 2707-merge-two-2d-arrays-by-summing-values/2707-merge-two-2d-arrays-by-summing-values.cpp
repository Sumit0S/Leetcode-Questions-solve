class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) 
    {
        unordered_map<int,int> mp;
        for(int i=0; i<nums1.size(); i++){
            auto val1=nums1[i];
            mp[val1[0]]=val1[1];
        }

        vector<vector<int>> ans;
        for(auto it:nums2){
            mp[it[0]]+=it[1];

        }

        for(auto it:mp)
        {
            ans.push_back({it.first,it.second});
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};