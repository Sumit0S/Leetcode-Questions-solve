class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        set<pair<int,pair<int,int>>> st;

        int dr[] = {-1, 0, 1, 0}; 
        int dc[] = {0, 1, 0, -1};
        st.insert({0,{0,0}});

        while(!st.empty()){
            auto it = *(st.begin());
            st.erase(it);
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == n - 1 && col == m - 1) {
                return dis;
            }
            for(int i=0; i<4; i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m){
                    int neweffort=max(dis,abs(heights[nrow][ncol]-heights[row][col]));
                    if(neweffort<dist[nrow][ncol]){
                        dist[nrow][ncol]=neweffort;
                        st.insert({neweffort,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};