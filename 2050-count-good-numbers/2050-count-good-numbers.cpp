class Solution {
public:
    int countGoodNumbers(long long n) {
        if(n==1){
            return 5;
        }
        if(n%2==0){
            long long ans=4;
            return (ans*countGoodNumbers(n-1))%1000000007;
        }
        else{
            long long ans=5;
            return (ans*countGoodNumbers(n-1))%1000000007;
        }
    }
};