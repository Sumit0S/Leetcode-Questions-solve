class Solution {
public:
    string removeOuterParentheses(string s)
    {
         string sa="";
         int cnt=0;
         for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                cnt+=1;
            }
            else{
                cnt-=1;
            }
            if(cnt==1 and s[i]=='('){
                continue;
            }
            else if(cnt==0 and s[i]==')'){
                continue;
            }
            sa+=s[i];

         }
         return sa;
    }
};