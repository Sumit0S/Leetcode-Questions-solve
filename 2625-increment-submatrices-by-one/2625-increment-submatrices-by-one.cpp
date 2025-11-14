class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) 
    {
        vector<vector<int>> ans(n,vector<int> (n,0));

        sort(queries.begin(),queries.end());

        for(auto it:queries){
            int row1=it[0];
            int col1=it[1];
            int row2=it[2];
            int col2=it[3];

            for(int x=row1; x<=row2; x++){
                for(int y=col1; y<=col2; y++)
                {
                    if(row1 <= x && x <= row2 && col1 <= y && y <= col2)
                        {
                            ans[x][y]=1+ans[x][y];
                        }
                }
            }
        }
        return ans;
    }
};