class Solution {
public:
    int maxDepth(string s) 
    {
        int ans=0;
        int cnt=0;
        for(char it:s){
            if(it=='('){
                cnt++;
            }
            else if(it==')'){
                cnt--;
            }
            ans=max(cnt,ans);
        }    
        return ans;
    }
};