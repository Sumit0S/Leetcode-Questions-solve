class Solution {
public:

    void dfs(int row,int col,vector<vector<bool>> &visited,vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        visited[row][col]=true;
        int drow[4]={0,-1,0,1};
        int dcol[4]={1,0,-1,0};
        
        for(int i=0; i<4; i++){
            int r=row+drow[i];
            int c=col+dcol[i];
            if(r>=0 and r<n and c>=0 and c<m and !visited[r][c] and board[r][c]=='O'){
                dfs(r,c,visited,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' and (i==0 or j==0 or i==n-1 or j==m-1)){
                    q.push({i,j});
                    cout<<i<<" "<<j<<endl;
                }
            }
        }

        vector<vector<bool>> visited(n,vector<bool>(m,false));

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            dfs(row,col,visited,board);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }

    }
};