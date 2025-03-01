class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==0){
                nums[i]=0;
                cnt++;
            }
            else{
                nums[i]=1;
            }
        }

        int j=0;
        while(j<cnt){
            nums[j]=0;
            j++;
        }
        while(j<nums.size()){
            nums[j]=1;
            j++;
        }

        return nums;
    }
};