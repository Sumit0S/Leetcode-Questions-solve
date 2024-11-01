class Solution {
public:
    string makeFancyString(string s) {
        int cnt=1;
        if(s.length()<=2){
            return s;
        }
        string ans=s;
        for(int i=1; i<s.length(); i++){
            if(s[i]==s[i-1]){
                cnt+=1;
            }
            if(s[i]!=s[i-1]){
                cnt=1;
            }
            if(cnt>=3){
                ans[i]='1';
                // cnt=1;
            }


        }
        string new_ans="";
        for(int i=0; i<ans.length(); i++){
            if(ans[i]!='1'){
                new_ans+=ans[i];
            }
        }
        return new_ans;
    }
};