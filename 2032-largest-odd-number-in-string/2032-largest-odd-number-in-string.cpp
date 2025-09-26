class Solution {
public:
    string largestOddNumber(string num) 
    {
        int n=num.length()-1;
        while(n>=0){
            if((num[n]-'0')%2!=0){
                break;
            }
            n--;
        }
        string ans=num.substr(0,n+1);
        return ans;
    }
};