class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        vector<bool> chotabhai(nums.size());
        vector<bool> badabhai(nums.size());

        int mini=nums[0];
        for(int i=1;  i<nums.size(); i++){
            if(nums[i]>mini){
                chotabhai[i]=true;
            }
            else{
                mini=min(mini,nums[i]);
            }
        }

        int maxi=nums[nums.size()-1];

        for(int i=nums.size()-2;  i>=0; i--){
            if(nums[i]<maxi){
                badabhai[i]=true;
            }
            else{
                maxi=max(maxi,nums[i]);
            }
        }

        for(int i=0; i<nums.size(); i++){
            cout<<badabhai[i]<<" ";

        }

        for(int i=0; i<nums.size(); i++){
            if(chotabhai[i] and badabhai[i]){
                return true;
            }
        }
        return false;
    }
};