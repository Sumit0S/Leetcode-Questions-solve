class Solution {
public:
    int candy(vector<int>& ratings) {
        int cndy=1;
        int sum=0;
        vector<int> left(ratings.size(),1);
        vector<int> right(ratings.size(),1);

        int n=ratings.size();
        if (n == 0) return 0;
        left[0]=1;
        left[n-1]=1;
        for(int i=1; i<ratings.size(); i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }
            else{
                cndy=1;
                left[i]=cndy;
            }
        }

        for(int i=n-2; i>=0; i--)
        {
            if(ratings[i]>ratings[i+1]){
                right[i]=right[i+1]+1;
            }
            else{
                cndy=1;
                right[i]=cndy;
            }
        }

        for(int i=0; i<ratings.size(); i++){
            sum+=max(left[i],right[i]);
        }
        return sum;
    }
};