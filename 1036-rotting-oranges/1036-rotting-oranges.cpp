class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();



        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<pair<int,int>,int>> q;
        int freshcount=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1){
                    freshcount++;
                }
            }
        }

        int rowDir[] = {-1, 0, +1, 0};  
        int colDir[] = {0, 1, 0, -1};
        int time=0;
        int cnt=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int tm=q.front().second;
            q.pop();
            time=max(time,tm);

            for(int i=0; i<4; i++){
                int nrow=r+rowDir[i];
                int ncol=c+colDir[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==0 and grid[nrow][ncol]==1)
                {
                    q.push({{nrow,ncol},tm+1});
                    vis[nrow][ncol]=1;
                    cnt++;
                }
            }
        }

        if(cnt!=freshcount){
            return -1;
        }
        return time;
    }
};