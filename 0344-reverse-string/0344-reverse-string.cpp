class Solution {
public:


    void rec(vector<char>& s,int i,int n)
    {
        if(i>n){
            return;
        }
        int temp=s[i];
        s[i]=s[n];
        s[n]=temp;
        rec(s,i+1,n-1);
    }
    void reverseString(vector<char>& s) 
    {
        int n=s.size()-1;
        rec(s,0,n);
    }
};