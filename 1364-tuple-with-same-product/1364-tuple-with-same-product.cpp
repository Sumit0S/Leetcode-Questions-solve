class Solution {
public:
int v=0;
    void calcul(int ind,vector<int>& nums,map<int,int>& ans){
        if(ind==nums.size()){
            return;
        }
        for(int i=ind; i<nums.size(); i++){
            int val=nums[ind]*nums[i];
            if(i!=ind){v+=ans[val]++;}
        }
        calcul(ind+1,nums,ans);
    }
    int tupleSameProduct(vector<int>& nums) 
    {
        map<int,int> ans;
        calcul(0,nums,ans);
        int ans6=0;
        for(auto it:ans){
            if(it.second>1){
                ans6+=it.second;
            }
        }
        return v*8;
    }
};