class Solution {
public:
    bool isCircularSentence(string sentence) {

        
        int n=sentence.size();

        for(int i=1; i<n; i++){
            if(sentence[i]==' '){
                if(sentence[i-1]!=sentence[i+1]){
                    return false;
                }
            }
        }

        if(sentence[0]==sentence[sentence.size()-1]){
            return true;
        }
        else{
             return false;
        }
        
        return true;
    }
};