class Solution {
public:

    void solve(vector<vector<int>>& v,vector<vector<int>>& isConnected){
        int n=isConnected.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<isConnected[i].size(); j++){
                if(isConnected[i][j]==1){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
    }

    void dfs(int i,vector<bool> &visited,vector<vector<int>> &v){
        visited[i]=true;
        for(int it:v[i]){
            if(!visited[it]){
                dfs(it,visited,v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        vector<vector<int>> v(n);
        solve(v,isConnected);
        vector<bool> visited(n,false);
        int cnt=0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cnt++;
                dfs(i, visited, v);
            }
        }
        
        return cnt;
    }
};