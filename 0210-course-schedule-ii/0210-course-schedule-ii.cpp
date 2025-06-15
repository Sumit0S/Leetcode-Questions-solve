class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> freq(numCourses,0);

        vector<vector<int>> adj(numCourses);

        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        for(int i=0; i<numCourses; i++){
            for(auto it:adj[i]){
                freq[it]++;
            }
        }

        queue<int> q;

        for(int i=0; i<numCourses; i++){
            if(freq[i]==0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto it:adj[front]){
                freq[it]--;
                if(freq[it]==0){
                    q.push(it);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        vector<int> vv;
        return ans.size()==numCourses?ans:vv;
    }
};