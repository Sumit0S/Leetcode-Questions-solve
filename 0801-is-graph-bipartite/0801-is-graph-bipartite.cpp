class Solution {
public:

    bool bfs(int u,vector<int>&vis,vector<int>&color,vector<vector<int>>& A)
    {
        queue<int>q;

        q.push(u);
        
        vis[u]=1,color[u]=0;

        while(!q.empty())
        
        {
        
            int u=q.front();q.pop();

            for(auto& v: A[u])
                if(!vis[v])
                    vis[v]=1,
                    color[v]=!color[u],
                    q.push(v);
                else if(color[v]==color[u])
                    return 0;
        }
        return 1;
    }

public:
    bool isBipartite(vector<vector<int>>& A) 
    {

        int n=A.size();

        vector<int> vis(n,0) , color(n,-1);

        queue<int>q;
        for(int i=0;i<n;i++)
            if(!vis[i])
                if(!bfs(i,vis,color,A)) return 0;
        return 1;
    }
};