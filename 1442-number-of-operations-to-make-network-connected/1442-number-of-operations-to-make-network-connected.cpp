class Solution {
public:

    int find(vector<int> &parent,int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=find(parent,parent[node]);

    }

    void unionSets(vector<int> &parent, int u, int v) {
        int ulpu = find(parent, u);
        int ulpv = find(parent, v);
        // Union by setting one root as the parent of the other
        parent[ulpu] = ulpv;
    }

    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        vector<int> parent(n);

        for(int i=0; i<n; i++){
            parent[i]=i;
        }
        int cntExtra=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            
            int ulpu=find(parent,u);
            int ulpv=find(parent,v);

            if(ulpu==ulpv){
                cntExtra+=1;
            }
            else{
                unionSets(parent,u,v);
            }
        }
        int val=0;
        for(int i=0; i<n; i++){
            if(parent[i]==i){
                val++;
            }
        }
        if(cntExtra>=val-1){
            return val-1;
        }
        else{
            return -1;
        }
    }

};