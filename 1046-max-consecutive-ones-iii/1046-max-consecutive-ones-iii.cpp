class Solution {
public:
    int longestOnes(vector<int>& arr, int k) 
    {
        int l=0;
        int zeros=0;
        int ans=0;
        for(int r=0; r<arr.size(); r++)
        {
            if(arr[r]==0)
            {
                zeros++;
            }
            if(zeros>k and l<r){  
                if(arr[l]==0){ 
                    zeros--;
                }
                
                l++;
            }
       
            if(zeros<=k) 
            {
                ans=max(ans,r-l+1);
            }
            
        }
        return ans;
    }
};
