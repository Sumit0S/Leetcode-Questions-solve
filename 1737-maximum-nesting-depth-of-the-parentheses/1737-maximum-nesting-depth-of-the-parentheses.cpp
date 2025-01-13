class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int ans=INT_MIN;
        if(s.length()==1){
            return 0;
        }
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                cnt++;
            }
            else if(s[i]==')'){
                ans=max(ans,cnt);
                cnt--;
            }
        }
        if(ans==INT_MIN){
            return 0;
        }
        return ans;
    }
};