class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) 
    {
        int n=arr.size();
        int left=0;
        int right=n-1;
        
        for(int i=1; i<n; i++){
            if(arr[i-1]<=arr[i]){
                left=i;
            }
            else{
                break;
            }
        }

        for(int i=n-2; i>=0; i--){
            if(arr[i]<=arr[i+1]){
                right=i;
            }
            else{
                break;
            }
        }

        if(right==0){
            return 0;
        }
        
        int result=min(n-left-1,right);
        int i=0,j=right;
        while(i<=left and j<n){
            if(arr[i]<=arr[j]){
                result=min(result,j-i-1);
                i++;
            }
            else{
                j++;
            }
        }
        return result;
    }
};