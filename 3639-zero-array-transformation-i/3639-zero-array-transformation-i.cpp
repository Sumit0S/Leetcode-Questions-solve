class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        vector<int> v(nums.size(),0);
        for(int i=0; i<queries.size(); i++){
            auto range=queries[i];
            int first=range[0];
            int second=range[1];

            v[first]+=1;
            if(second+1<nums.size()){
                v[second+1]-=1;
            }
        }

        for(int i=1; i<v.size(); i++){
            v[i]=v[i]+v[i-1];
        }

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>v[i]){
                return false;
            }
        }
        return true;
    }
};