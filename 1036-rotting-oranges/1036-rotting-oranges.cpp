class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int,int>,int>> q;
        int freshcount = 0;

        // Initialize the queue with rotten oranges and count fresh oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});  // Push rotten oranges to queue with time 0
                    vis[i][j] = 2;        // Mark visited
                } 
                else if(grid[i][j] == 1) {
                    freshcount++;          // Count fresh oranges
                }
            }
        }

        // Early exit if there are no fresh oranges
        if(freshcount == 0) return 0;

        int rowDir[] = {-1, 0, +1, 0};  
        int colDir[] = {0, 1, 0, -1};
        int time = 0;

        // BFS to rot fresh oranges
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int tm = q.front().second;
            q.pop();
            time = max(time, tm);

            for(int i = 0; i < 4; i++) {
                int nrow = r + rowDir[i];
                int ncol = c + colDir[i];

                // Check boundaries and if the orange is fresh and not yet visited
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, tm + 1});
                    vis[nrow][ncol] = 2;  // Mark as visited
                    freshcount--;  // Decrease the count of fresh oranges

                    // If all fresh oranges have rotted, return the time
                    if(freshcount == 0) {
                        return tm + 1;
                    }
                }
            }
        }

        // If there are still fresh oranges, return -1
        return -1;
    }
};
