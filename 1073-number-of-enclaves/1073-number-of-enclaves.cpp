class Solution {
public:

    // Helper function to perform DFS and mark all connected land cells
    void dfstraversal(int r, int c, vector<vector<int>>& ans, vector<vector<int>>& vis) {
        int n = ans.size();
        int m = ans[0].size();
        vis[r][c] = 1;

        // Direction vectors for moving up, right, down, left
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1}; 

        for (int i = 0; i < 4; i++) {
            int rdir = r + delRow[i];
            int cdir = c + delCol[i];

            // Check if the neighboring cell is valid, unvisited, and part of land
            if (rdir >= 0 && rdir < n && cdir >= 0 && cdir < m && 
                !vis[rdir][cdir] && ans[rdir][cdir] == 1) {
                dfstraversal(rdir, cdir, ans, vis);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& ans) {
        int n = ans.size();
        int m = ans[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Traverse the boundary of the grid and mark all reachable land cells
        for (int i = 0; i < m; i++) {
            // First row
            if (ans[0][i] == 1 && !vis[0][i]) {
                dfstraversal(0, i, ans, vis);
            }
            // Last row
            if (ans[n - 1][i] == 1 && !vis[n - 1][i]) {
                dfstraversal(n - 1, i, ans, vis);
            }
        }

        for (int i = 0; i < n; i++) {
            // First column
            if (ans[i][0] == 1 && !vis[i][0]) {
                dfstraversal(i, 0, ans, vis);
            }
            // Last column
            if (ans[i][m - 1] == 1 && !vis[i][m - 1]) {
                dfstraversal(i, m - 1, ans, vis);
            }
        }

        // Count enclaved cells (land not connected to the boundary)
        int enclaves = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ans[i][j] == 1 && !vis[i][j]) {
                    enclaves++;
                }
            }
        }

        return enclaves;
    }
};
