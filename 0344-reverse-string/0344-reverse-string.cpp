class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            // Swap the characters
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            
            // Move towards the center
            left++;
            right--;
        }
    }
};