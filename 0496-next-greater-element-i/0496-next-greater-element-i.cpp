class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        map<int,int> m;
        vector<int> v;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i]==nums2[j]){
                    
                    m[nums1[i]]=j;
                }
            }
        }

        for(int i=0; i<nums1.size(); i++){
            cout<<m[nums1[i]]<<" ";
        }
        for(int i=0; i<nums1.size(); i++){
            bool a=true;
            for(int j=m[nums1[i]]; j<nums2.size(); j++){
                if(nums2[j]>nums1[i]){
                    v.push_back(nums2[j]);
                    a=false;
                    break;
                }
            }
            if(a){
                v.push_back(-1);
            }
        }

        return v;
    }
};