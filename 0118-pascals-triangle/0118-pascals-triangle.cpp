class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> v(numRows);
        for(int i=0; i<numRows; i++){
            v[i].resize(i + 1);
            v[i][0] = v[i][i] = 1;
            for(int j=1; j<i; j++){
                // if(j==0 or j==i){
                //     v[i][j]=0;
                // }
                if(j!=0 or j!=i){
                    v[i][j]=v[i-1][j-1]+v[i-1][j];
                    
                }                
            }
        }
        return v;
    }
};