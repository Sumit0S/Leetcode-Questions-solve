class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        string temp="";
        string ans="";
        for(auto i:s){
            if(i=='('){
                temp.push_back('(');
                if(temp.size()>1){
                    ans.push_back(i);
                }
            }
            else{
                if(temp.size()>1){
                    ans.push_back(i);
                    temp.pop_back();
                }
                else{
                    if(!temp.empty()){
                        temp.pop_back();
                    }
                }
            }
        }  
        return ans;  
    }
};