
class Solution {
public:

    int cnti=0;

    void cnt(int i,int j,int m,int n){
        if(i==m-1 and j==n-1){
            cnti+=1;
            return;
        }
        if(i>=m or j>=n){

            return;
        }
        cnt(i+1,j,m,n);
        cnt(i,j+1,m,n);
        return;
    }

    int uniquePaths(int m, int n) {
        cnt(0,0,m,n);
        return cnti;
    }
};