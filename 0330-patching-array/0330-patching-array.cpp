class Solution {
public:
    int minPatches(vector<int>& nums, int n) 
    {
        int m=nums.size();
        long expectedsum=1;
        long sumformed=0;
        int patches=0;

        int i=0;
        while(sumformed<n){
            if(expectedsum<=sumformed){
                expectedsum=sumformed+1;
            }
            else{
                if(i<m and nums[i]<=expectedsum){
                    sumformed+=nums[i];
                    i++;
                }
                else{
                    patches++;
                    sumformed+=expectedsum;
                }
            }
        }
        return patches;

    }
};