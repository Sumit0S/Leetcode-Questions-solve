class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads)
    {
        vector<pair<int,int>> adj[n];

        for(auto it:roads){
            int i=it[0];
            int j=it[1];
            int w=it[2];
            adj[i].push_back({j,w});
            adj[j].push_back({i,w});
        }

        set<pair<long long,int>> st;
        st.insert({0,0});
        vector<int> ways(n,0);
        vector<long long> dist(n,1e18);
        ways[0]=1;
        dist[0]=0;

        int mod=(int)(1e9+7);
        while(!st.empty()){
            auto it = *(st.begin());
            long long dst=it.first;
            int node=it.second;
            st.erase(it);  
            for(auto it:adj[node]){
                int nn=it.first;
                int nd=it.second;
                if(dst+nd<dist[nn]){
                    dist[nn]=dst+nd;
                    ways[nn]=ways[node];
                    st.insert({dst+nd,nn});
                }
                else if(dst+nd==dist[nn]){
                    ways[nn]=(ways[nn]+ways[node])%mod;
                }
            }
        }   
        return ways[n-1]%mod; 
    }
};
