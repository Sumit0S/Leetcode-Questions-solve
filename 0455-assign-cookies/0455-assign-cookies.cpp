class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int l=0;
        int r=0;
        int cnt=0;
        while(l<g.size() and r<s.size())
        {
            if(g[l]<=s[r]){
                l++;
                r++;
                cnt++;
            }
            else if(g[l]>=s[r]){
                r++;
            }
        }     
        return cnt;
    }
};