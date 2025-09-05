class Solution {
public:

    static bool comp(vector<int> &a, vector<int> &b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(), comp);

        vector<vector<int>> ans;
        int i=0;
        while(i<n){
            int first=intervals[i][0];
            int second=intervals[i][1];

            int j=i+1;
            while(j<n and intervals[j][0]<=second){
                second=max(second,intervals[j][1]);
                j++;
            }
            i=j;
            ans.push_back({first,second});
        }
        return ans;
    }
};