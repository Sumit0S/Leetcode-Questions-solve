class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        int cnt=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0;
        int r=0;

        while(l<g.size() and r<s.size()){
            if(s[r]>=g[l]){
                l++;
                r++;
                cnt++;
            }
            else{
                r++;
            }
        }
        return cnt;
    }
};