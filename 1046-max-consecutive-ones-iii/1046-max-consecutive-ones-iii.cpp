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
            if(zeros>k){
                while(zeros!=k and l<r){
                    if(arr[l]==1){
                        l++;
                    }
                    else{
                        l++;
                        zeros--;
                    }
                }
            }
       
            if(zeros<=k) 
            {
                ans=max(ans,r-l+1);
            }
            
        }
        return ans;
    }
};