class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans(numRows,vector<int> (numRows,1));
        for(int i=0; i<numRows; i++){
            ans[i].resize(i+1);
            for(int j=1; j<i; j++){
                ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
            }
        }


        return ans;
    }
};