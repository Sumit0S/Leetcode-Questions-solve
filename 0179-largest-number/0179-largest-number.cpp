class Solution {
public:
   bool static compare(int a,int b){
       string ptr=to_string(a), qtr=to_string(b);
       return ptr+qtr>qtr+ptr;
   }
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end(), compare);
        string ans;
        for(int i=0; i<n; i++) ans+=to_string(nums[i]);
        if(ans[0]=='0') return "0";
        return ans;
    }
};