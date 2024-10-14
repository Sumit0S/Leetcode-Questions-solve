class Solution {
public:
    long long maxKelements(vector<int>& nums, int k)
    {
        long long ans=0;
        priority_queue<int> q;

        for(int i=0; i<nums.size(); i++){
            q.push(nums[i]);
        }

        while(k>0){
            long long val=q.top();
            q.pop();
            cout<<val<<" ";
            ans+=val;
            q.push((val+2)/3);
            k--;
        }
        return ans;
    }
};