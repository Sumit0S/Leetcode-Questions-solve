class Solution {
public:
    string removeOuterParentheses(string s) 
    {
       int cnt=0;
       string ans="";
       for(int i=0; i<s.length(); i++){
            if(s[i]=='(')
            {
                cnt++;
            }
            if((s[i]=='(' and cnt>1) or s[i]==')'){
                if(s[i]==')'){
                    cnt--;
                }
                if(cnt!=0){
                    ans+=s[i];
                }
            }
       }
       return ans;
    }
};