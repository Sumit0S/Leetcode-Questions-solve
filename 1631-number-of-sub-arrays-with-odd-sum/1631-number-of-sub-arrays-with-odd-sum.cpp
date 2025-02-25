class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        int countodd=0;
        int counteven=1;

        int ans=0;
        int prefixsum=0;
        for(int i=0; i<arr.size(); i++){
            prefixsum+=arr[i];
            if(prefixsum%2==0){
                ans=(ans+countodd)%1000000007;
                counteven++;
            }
            else{
                ans=(ans+counteven)%1000000007;
                countodd++;
            }
        }
        return ans%1000000007;
    }
};