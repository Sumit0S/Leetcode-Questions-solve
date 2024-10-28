class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    
    {
        int n = nums.size();
        
        k = k % n;

        if (k == 0) return; 
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.begin()+n-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};