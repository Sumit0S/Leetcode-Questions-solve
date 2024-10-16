class Solution {
public:
    typedef pair<int,char> P;
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<P,vector<P>> pq;

        if(a>0){
            pq.push({a,'a'});
        }
        if(b>0){
            pq.push({b,'b'});
        }
        if(c>0){
            pq.push({c,'c'});
        }

        string result="";

        while(!pq.empty()){
            int val=pq.top().first;
            char c=pq.top().second;
            pq.pop();

            int l=result.length();

            if(l>=2 and result[l-1]==c and result[l-2]==c){
                
                if(pq.empty()){
                    break;
                }
                int nval=pq.top().first;
                char nc=pq.top().second;
                pq.pop();
                nval--;
                result.push_back(nc);
                if(nval>0){
                    pq.push({nval,nc});
                }
            }
            else{
                val--;
                result.push_back(c);
            }

            if(val>0){
                pq.push({val,c});
            }



        }
        return result;
    }
};