class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k)
    {

        for(int i=0; i<grid.size(); i++){
            sort(grid[i].begin(),grid[i].end());
        }
        priority_queue<int> q;
        for(int i=0; i<grid.size(); i++){
            int limit=limits[i];
            for(int j=grid[0].size()-1; j>=0; j--){
                if(limit>0){
                    // cout<<grid[i][j]<<" ";
                    q.push(grid[i][j]);
                }
                limit--;
            }
        }

        long long int ans=0;
        while(k>0){
            ans+=q.top();
            q.pop();
            k--;
        }
        return ans;
    }
};