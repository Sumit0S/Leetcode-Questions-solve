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

        parent[ulpu] = ulpv;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        vector<int> parent(maxRow + maxCol+2);
        for(int i=0; i<parent.size(); i++){
            parent[i]=i;
        }
        unordered_map<int,int> storeNodes;
        for(auto it:stones){
            int ru=it[0];
            int rc=it[1]+maxRow+1;

            unionSets(parent,ru,rc);
            storeNodes[ru]=1;
            storeNodes[rc]=1;
        }

        int cnt = 0;
        for (const auto& it : storeNodes) {
            // Count unique connected components (i.e., distinct root parents)
            if (find(parent, it.first) == it.first) {
                cnt++;
            }
        }

        // The result is total stones minus the number of unique components
        return n - cnt;
    }
};