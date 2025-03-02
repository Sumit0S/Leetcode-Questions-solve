class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) 
    {
        vector<vector<int>> ans;
        int l=0; 
        int r=0;

        while(l<nums1.size() and r<nums2.size())
        {
            auto it1=nums1[l];
            auto it2=nums2[r];
            if(it1[0]==it2[0]){
                ans.push_back({it1[0],it1[1]+it2[1]});
                l++;
                r++;
            }
            else if(it1[0]<it2[0]){
                ans.push_back(it1);
                l++;
            }
            else{
                ans.push_back(it2);
                r++;
            }
        }

        while(l<nums1.size()){
            auto it1=nums1[l];
            ans.push_back(it1);
            l++;
        }

        while(r<nums2.size()){
            auto it1=nums2[r];
            ans.push_back(it1);
            r++;
        }
        return ans;
    }
};