class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> pq;
        if (grid[0][0] != 0 || grid[n-1][m-1] != 0)
            return -1;
            
        pq.push({{0,0},1});

        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));

        dist[0][0]=1;

        int drow[8] = {0, -1, -1, -1, 0, 1, 1, 1};
        int dcol[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

        while(!pq.empty()){
            int row=pq.front().first.first;
            int col=pq.front().first.second;
            int wgt=pq.front().second;
            pq.pop();

            for(int i=0; i<8; i++){
                int crow=row+drow[i];
                int ccol=col+dcol[i];
                if(crow>=0 and crow<n and ccol>=0 and ccol<m and grid[crow][ccol]==0 and 1+wgt<dist[crow][ccol]){
                    dist[crow][ccol]=1+wgt;
                    pq.push({{crow,ccol},1+wgt});
                }
            }
        }
        return dist[n-1][m-1] == INT_MAX ? -1 : dist[n-1][m-1];
    }
};