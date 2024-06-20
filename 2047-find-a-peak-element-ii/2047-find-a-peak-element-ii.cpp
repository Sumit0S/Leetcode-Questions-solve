class Solution {
public:

    int findmaxelement(vector<vector<int>>& mat,int col)
    {
        int max_el=-1;
        int index=-1;
        for(int i=0; i<mat.size(); i++){
            if(mat[i][col]>max_el){
                max_el=max(max_el,mat[i][col]);
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n=mat.size();
        int m=mat[0].size();
        int low=0 , high=m-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            int maxRowindex=findmaxelement(mat,mid);
            
            int left = (mid - 1 >= 0) ? mat[maxRowindex][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[maxRowindex][mid + 1] : -1;

            if(left<mat[maxRowindex][mid] and mat[maxRowindex][mid]>right){
                return {maxRowindex,mid};
            }
            if(mat[maxRowindex][mid]<left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};