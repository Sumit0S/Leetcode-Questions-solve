class Solution {
public:
    bool hasSameDigits(string s)
    {
        string temp=s;
        int n=s.length();
        while(temp.length()>2){
            string ss="";
            for(int i=0; i<temp.length(); i++){
                if(i+1<temp.length()){
                    ss+=to_string((temp[i]-'0'+temp[i+1]-'0')%10);
                    cout<<temp<<" ";
                }
            }
            temp=ss;
        }
        if(temp.length()==2){
            return temp[0]==temp[1];
        } 
        else{
            return false;
        }
    }
};