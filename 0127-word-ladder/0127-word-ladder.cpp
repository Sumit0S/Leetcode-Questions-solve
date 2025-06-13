class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
            string s=q.front().first;
            int lvl=q.front().second;

            q.pop();

            if(endWord==s){
                return lvl;
            }
            for(int i=0; i<s.length(); i++){
                char orignal=s[i];
                for(char c='a'; c<='z'; c++){
                    s[i]=c;
                    if(st.find(s)!=st.end()){
                        q.push({s,lvl+1});
                        st.erase(s);
                    }
                }
                s[i]=orignal;
            }
        }
        return 0;
    }
};