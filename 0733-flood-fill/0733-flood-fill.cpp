class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int n=image.size();
        int m=image[0].size();
        int row[4]={0,-1,0,1};
        int col[4]={1,0,-1,0};


        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<int,int>> q;

        int c1=image[sr][sc];
        q.push({sr,sc});

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int crow=r+row[i];
                int ccol=c+col[i];
                if(crow>=0 and crow<n and ccol>=0 and ccol<m and !visited[crow][ccol] and image[crow][ccol]==c1){
                    q.push({crow,ccol});
                    image[crow][ccol]=color;
                    visited[crow][ccol]=true;
                }
            }
        }
        image[sr][sc]=color;
        return image;
    }
};