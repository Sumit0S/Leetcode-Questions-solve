class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int ans=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                cnt++;
                if(cnt>0){
                    ans=max(ans,cnt);
                }
            }
            else if(s[i]==')'){
                cnt--;
                if(cnt<0){
                    return 0;
                }
            }
        }
        return ans;
    }
};