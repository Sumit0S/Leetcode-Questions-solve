class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int size=matrix.size();
        int var=1;
        if(size==0){
            return;
        }
        for(int i=0; i<size; i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){

                    matrix[i][0]=0;
                    
                    if(j!=0){
                    matrix[0][j]=0;
                    }
                    
                    else{
                        var=0;
                    }
                }
            }
        }

        for(int i=1; i<size; i++){
            for(int j=1; j<matrix[0].size(); j++){
                if(matrix[i][j]!=0){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
                }
            }
        }
        if(matrix[0][0]==0){
            for(int i=0; i<matrix[0].size(); i++){
                matrix[0][i]=0;
            }
        }

        
        if(var==0){
            for(int i=0; i<matrix.size(); i++){
                matrix[i][0]=0;
            }
        }      

    }
};