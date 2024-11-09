class Solution {
public:
    bool rotateString(string s, string goal) {

        for(int i=0; i<s.length(); i++){
            if(s==goal){
                return true;
            }
            reverse(s.begin(),s.end());
            reverse(s.begin()+1,s.end());
        }
        return false;
    }
};


