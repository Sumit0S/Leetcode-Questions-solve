class Solution {
public:
    int largestCombination(vector<int>& candidates) 
    {
        int ans=0;
        for(int i=0; i<31; i++){
            int freq=0;
            for(auto ele:candidates){
                if(ele & (1<<i)){
                    freq++;
                }
            }
            ans=max(ans,freq);
        }
        return ans;
    }
};