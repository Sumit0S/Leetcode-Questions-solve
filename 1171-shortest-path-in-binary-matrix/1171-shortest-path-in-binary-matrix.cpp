class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {

        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) {
            return -1;
        }
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 1;
        q.push({1, {0,0}});


        int dr[] = {-1, 0, 1, 0, -1, -1, 1, 1}; 
        int dc[] = {0, 1, 0, -1, -1, 1, -1, 1}; 

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;

            if (row == n - 1 && col == m - 1) {
                return dis;
            }
            for(int i=0; i<8; i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==0 and dis+1<dist[nrow][ncol]){
     
                        dist[nrow][ncol]=dis+1;
                        q.push({dis+1,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};