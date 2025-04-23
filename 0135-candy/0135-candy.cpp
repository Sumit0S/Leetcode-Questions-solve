class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        vector<int> v(ratings.size(),1);
        vector<int> v2(ratings.size(),1);
        for(int i=0; i<ratings.size(); i++)
        {
            if(i>0 and (ratings[i-1]<ratings[i]))
            {
                v[i]=v[i-1]+1;
            }
        }

        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])
                v2[i] = v2[i + 1] + 1;
        }

        int ans=0;

        for(int i=0; i<ratings.size(); i++){
            cout<<v2[i]<<" ";
            ans+=max(v[i],v2[i]);
        }
        return ans;
    }
};