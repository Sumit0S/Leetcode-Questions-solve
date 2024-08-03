class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums){
        
        int i=2*nums.size()-1;
        vector<int> v(nums.size(),-1);
        stack<int> st;
        while(i>=0)
        {
            while(!st.empty() and nums[i%nums.size()]>=st.top()){
                st.pop();
            }

            if(!st.empty() and i<nums.size())
            {
                v[i]=st.top();
            }
            st.push(nums[i%nums.size()]);
            i--;
        }
        return v;
    }
};