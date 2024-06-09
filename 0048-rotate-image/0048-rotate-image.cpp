class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       std::ios_base::sync_with_stdio(false);
       std::cout.tie(0);
        int row=matrix.size();
        int col=matrix[0].size();

        for(int i=0; i<row; i++){
            for(int j=i+1; j<col; j++){

                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0; i<row; i++ ){
            reverse(matrix[i].begin(),matrix[i].end());
        }

    }
};