class Solution {
public:
    double myPow(double x, int n) {
        // Handle base case
        if (n == 0) {
            return 1;
        }
        
        long long N = n;
        // Handle negative powers
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        return power(x, N);
    }

private:
    double power(double x, long long n) {
        if (n == 0) {
            return 1;
        }
        if (n % 2 == 0) {
            double half = power(x, n / 2);
            return half * half;
        } else {
            double half = power(x, n / 2);
            return half * half * x;
        }
    }
};
