class Solution {
public:
    const int MOD = 1000000007;

    long long modPow(long long x, long long y)
    {
        if(y==0){
            return 1;
        }
        if(y%2==0){
            long long result=modPow(x,y/2);
            return ((result*result))%MOD;
        }

        else{
            long long result=modPow(x,(y-1)/2);
            return ( (x * result * result))%MOD;
        }
    }

    int monkeyMove(int n) 
    {
        return (modPow(2,n)-2+MOD)%MOD;    
    }
};