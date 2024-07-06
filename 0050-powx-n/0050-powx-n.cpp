class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        
        long long N=n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        if (n % 2 == 0) {
            double half = myPow(x, N / 2);
            return half * half;
        } else {
            double half = myPow(x, N / 2);
            return half * half * x;
        }
    }
};
