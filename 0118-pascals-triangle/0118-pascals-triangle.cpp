class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       std::ios_base::sync_with_stdio(false);
       std::cout.tie(0);
 vector<vector<int>> v(numRows); // Initialize the outer vector with numRows rows
        
        for(int i = 0; i < numRows; i++) {
            v[i].resize(i + 1); // Resize each row to have (i+1) elements
            v[i][0] = v[i][i] = 1; // Set the first and last elements of each row to 1
            
            // Fill in the values for the rest of the row
            for(int j = 1; j < i; j++) {
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j]; // Compute the value based on the previous row
            }
        }
        
        return v;
    }
};