class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        int cnt=0;
        string ans="";
        for(auto i:s){
            if(i=='('){
                cnt+=1;
                if(cnt>1){
                    ans.push_back(i);
                }
            }
            else{
                cnt-=1;
                if(cnt>=1){
                    ans.push_back(i);
                }
            }
        }    
        return ans;
    }
};