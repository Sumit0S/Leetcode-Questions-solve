class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0){
                int k=i+1;
                while(k<nums.size() and nums[k]==0){
                    k+=1;
                }
                if(k<nums.size()){
                    swap(nums[i],nums[k]);
                };
                cout<<i<<" "<<k<<" "<<endl;
            }
        }
    }
};