class Solution {
public:

    void dfstraversal(int r,int c,vector<vector<char>>& ans,vector<vector<int>> &vis)
    {
        int n=ans.size();
        int m = ans[0].size();
        vis[r][c]=1;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1}; 
        for(int i=0; i<4; i++){
            int rdir=r+delRow[i];
            int cdir=c+delCol[i];
            if(rdir>=0 and rdir<n and cdir>=0 and cdir<m and !vis[rdir][cdir] and ans[rdir][cdir]=='O'){
                dfstraversal(rdir,cdir,ans,vis);
            }
        }
    }
    void solve(vector<vector<char>>& ans) 
    {
        int n=ans.size();
        int m = ans[0].size();

        vector<vector<char>> board=ans;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0; i<m; i++){
            int row1=board[0][i];
            int row2=board[n-1][i];
            if(row1=='O')
            {
                if(!vis[0][i]){
                    dfstraversal(0,i,ans,vis);
                }
            }
            if(row2=='O'){
                if(!vis[n-1][i]){
                    dfstraversal(n-1,i,ans,vis);
                }
            }
        }    

        for(int i=0; i<n; i++){
            int row1=board[i][0];
            int row2=board[i][m-1];
            if(row1=='O')
            {
                if(!vis[i][0]){
                    dfstraversal(i,0,ans,vis);
                }
            }
            if(row2=='O'){
                if(!vis[i][m-1]){
                    dfstraversal(i,m-1,ans,vis);
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==1){
                    ans[i][j]='O';
                }
                else{
                    ans[i][j]='X';
                }
            }
        }
    }
};