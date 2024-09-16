class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    map<int, int> mpp;

    for(int i = 0; i < nums.size(); i++){
        int is_ans = target - nums[i];

        // Check if the complement exists in the map
        if(mpp.find(is_ans) != mpp.end()){
            ans.push_back(mpp[is_ans]);  // Get the index of the complement
            ans.push_back(i);            // Current index
            break;
        }

        // Insert the current number and its index into the map
        mpp[nums[i]] = i;
    }

    return ans;

}

};