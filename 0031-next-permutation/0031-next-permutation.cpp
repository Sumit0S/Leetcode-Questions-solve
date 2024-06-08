class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
       std::ios_base::sync_with_stdio(false);
       std::cout.tie(0);
       next_permutation(nums.begin(),nums.end());
    }
};