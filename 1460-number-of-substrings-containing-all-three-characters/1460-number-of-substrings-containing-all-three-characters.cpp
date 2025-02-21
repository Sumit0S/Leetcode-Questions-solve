class Solution {
public:
    int numberOfSubstrings(string s)
    {
        int lastseen[3]={-1,-1,-1};
        int cnt=0;
        for(int r=0; r<s.size(); r++)
        {
            lastseen[s[r]-'a']=r;
            if(lastseen[0]!=-1 and lastseen[1]!=-1 and lastseen[2]!=-1){
                cnt+=1+min(lastseen[0],min(lastseen[1],lastseen[2]));
            }

        }
        return cnt;
    }
};