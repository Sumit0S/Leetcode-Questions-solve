class Compare {
public:
    bool operator()(const pair<char,int> &a, const pair<char,int> &b) {
        return a.second<b.second;
    }
};
class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }

        priority_queue<pair<char,int>, vector<pair<char,int>>, Compare> pq;
        for(auto it : mp) pq.push(it);

        string ans="";
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int n=it.second;
            while(n>0){
                ans+=it.first;
                n--;
            }
        }
        return ans;
    }
};