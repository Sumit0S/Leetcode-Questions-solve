class Solution {
public:
    string reverseWords(string s) {
        string sa="";
        string ans="";
        if(s.empty()){
            return s;
        }
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]==' ' and sa.size()>0){
                reverse(sa.begin(),sa.end());
                ans+=sa;
                ans+=s[i];
                sa="";
            }
            else{
                if(s[i]!=' '){
                    sa+=s[i];
                }
                
            }
        }
        reverse(sa.begin(),sa.end());
        ans+=sa;
        if(ans[ans.size()-1]==' '){
            string temp="";
            for(int i=0; i<ans.size()-1; i++){
                temp+=ans[i];
            }
            return temp;
        }
        return ans;
    }
};