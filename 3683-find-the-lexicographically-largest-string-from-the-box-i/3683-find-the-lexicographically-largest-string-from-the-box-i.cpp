class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1)
            return word;

        int n=word.length();
        int minsplit=n-numFriends;

        string ans="";

        for(int i=0; i<n; i++){
            string curr=word.substr(i,minsplit+1);
            if(curr>ans){
                ans=curr;
            }
        }
        return ans;
    }
};