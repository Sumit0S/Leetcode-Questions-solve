class Solution {
public:
    string frequencySort(string s) {
         
         unordered_map<char, int> mp;
         priority_queue<pair<int, int>> pq;

         for(int i=0; i<s.size(); i++) {
              mp[s[i]]++;
         }

         for(auto it : mp) {
            pq.push({it.second, it.first});
         }

         string ans = "";

         while(!pq.empty()) {
            ans += string(pq.top().first, pq.top().second);
            pq.pop();
         } 
         
         return ans;
    }
};
