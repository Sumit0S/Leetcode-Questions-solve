class Solution {
public:


    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int> (m,0));


        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int> (m,0));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++){
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    ans[i][j]=0;
                    vis[i][j]=1;
                }
            }
        }
        int drow[]={0, 0, 1, -1};
        int dcol[]={1, -1, 0, 0};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int step=q.front().second;
            q.pop();
            ans[row][col]=step;
            for(int i=0; i<4; i++){
                int r=row+drow[i];
                int c=col+dcol[i];
                if(r>=0 and r<n and c>=0 and c<m and mat[r][c]==1 and !vis[r][c])
                {
                   
                    q.push({{r,c},step+1});
                    vis[r][c]=1;
                }
            }  
        }
        return ans;
    }
};