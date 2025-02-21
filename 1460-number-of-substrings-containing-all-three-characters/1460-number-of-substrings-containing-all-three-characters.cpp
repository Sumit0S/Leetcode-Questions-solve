class Solution {
public:

    int atMost(string &nums, int k) {
        if (k < 0) return 0;
        cout<<" --"<<k<<"-- ";
        unordered_map<char,int> mp;
        int l = 0, sum = 0, count = 0;
        for (int r = 0; r < nums.size(); ++r) {
            mp[nums[r]]++;
            while (mp.size() > k) {
                mp[nums[l]]--;
             if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]); // Remove character if count becomes zero
            }
                l++;
            }
            count += (r - l + 1);
    }
        return count;
    }
    int numberOfSubstrings(string s) {
        return atMost(s,3)-atMost(s,2);
    }
};