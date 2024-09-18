class Solution {
public:

    bool isp(int x, int &y) {
        if (x == 0) {
            return true;
        }
        bool result = isp(x / 10, y) && (x % 10 == y % 10);
        y /= 10;
        return result;
    }

    bool isPalindrome(int x) {
        if (x < 0) {
            return false;  
        }
        return isp(x, x); 
    }

};