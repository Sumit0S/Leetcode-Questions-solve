class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int n=image.size();
        int m=image[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int startColor = image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});

        vis[sr][sc] = 1;
        image[sr][sc] = color; 

        int nrow[]={0, 0, 1, -1};
        int ncol[]={1, -1, 0, 0};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nr=r+nrow[i];
                int nc=c+ncol[i];
                if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc] and image[nr][nc]==startColor){
                    q.push({nr,nc});
                    image[nr][nc]=color;
                    vis[nr][nc]=1;
                }
            }
        }
        return image;
    }
};