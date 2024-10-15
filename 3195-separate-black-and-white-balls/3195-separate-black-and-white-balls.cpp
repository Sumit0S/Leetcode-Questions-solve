class Solution {
public:
    long long minimumSteps(string s)
    {
        
        long long steps=0;
        long long cnt0=0;
        long long l=s.length()-1;
        for(int i=l; i>=0; i--){
            if(s[i]=='0'){
                cnt0+=1;
            }
            else if(s[i]=='1'){
                steps+=cnt0;
            }
        }
        
        return steps;
    }
};