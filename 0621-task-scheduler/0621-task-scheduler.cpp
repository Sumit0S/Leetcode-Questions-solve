class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) 
    {

        vector<int> mp(27,0);
        for(int i=0; i<tasks.size(); i++){
            mp[tasks[i]-'A']++;
        }
        priority_queue<int> pq;
        int ans=0;
        
        for(int it:mp){
            if(it>0){
                pq.push(it);
            }
            
        }

        while(!pq.empty()){
            vector<int> v;

            for(int i=0; i<=n; i++)
            {
                if(!pq.empty())
                {
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    v.push_back(freq);
                }

            }

            for(int &i:v){
                if(i>0){
                    pq.push(i);
                }
            }
            if(pq.empty())
            {
                ans+=v.size();
            }
            else
            {

                ans+=n+1;
            }

            cout<<ans<<" ";
        }
        return ans;
    }
};