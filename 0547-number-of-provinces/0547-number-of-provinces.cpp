class Solution {
public:
    void dfs(vector<int> adj[],vector<int> &visited,int start)
    {
        visited[start]=1;
        for(auto i: adj[start]){
            if(!visited[i]){
                dfs(adj,visited,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> visited (v, 0);
        int cnt = 0;

        vector<int> adj[v];

        for(int i=0; i<v; i++){
            for(int j=0; j<isConnected[i].size(); j++){
                if(isConnected[i][j]==1 and i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0; i<v; i++){
            if(!visited[i]){
                cnt++;
                dfs(adj,visited,i);
            }
        }
        return cnt;
    }
};