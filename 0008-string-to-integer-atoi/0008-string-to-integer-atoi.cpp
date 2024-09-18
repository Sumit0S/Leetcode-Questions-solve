class Solution {
public:
    void ignorespace(string &s,int &i){
        while(i < s.size() && s[i] == ' ') i++;
    }
    int myAtoi(string s) {
        int i=0;
        ignorespace(s,i);
        if(i == s.size()) return 0;
        
        long long maxi=INT_MAX,mini=INT_MIN,ans=0,sign=1;

        if(s[i]=='-'){
            i++;
            sign*=-1;
        }
        else if(s[i]=='+'){
            i++;
        }
        while(i<s.size()){
            if(s[i]<'0' || s[i]>'9'){
                return ans;
            }
            ans=ans*10+(sign*(s[i]-'0'));
            if(ans <= mini) return mini;
            if(ans >= maxi) return maxi;
            i++;
        }
        return ans;
    }
};