class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        int cnt=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(int i=0; i<g.size(); i++)
        {
            for(int j=i; j<s.size(); j++){
                if(s[j]>=g[i]){
                    cnt++;
                    s[j]=-1;
                    break;
                }
            }
        } 
        return cnt;
    }
};