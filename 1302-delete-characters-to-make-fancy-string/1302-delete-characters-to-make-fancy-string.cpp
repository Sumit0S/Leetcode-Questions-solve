class Solution {
public:
    string makeFancyString(string s) {
        if(s.length()<3){
            return s;
        }

        int n=s.length();

        for(int i=0; i<s.length()-2; i++){
            char s1=s[i];
            char s2=s[i+1];
            char s3=s[i+2];
            if(s1==s2 and s2==s3){
                s[i]='*';
            }
        }

        string ans="";
        for(auto i:s){
            if(i!='*'){
                ans.push_back(i);
            }
        }
        return ans;
    }
};