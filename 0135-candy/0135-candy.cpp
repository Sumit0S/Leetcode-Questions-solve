class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int sum=1;
        int n=ratings.size();
        int i=1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                i++;
                sum+=1;
                continue;
            }

            int peak=1;
            while(i<n and ratings[i-1]<ratings[i]){
                peak+=1;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n and ratings[i-1]>ratings[i]){
                sum+=down;
                down+=1;
                i++;
            }
            if(down-peak>0){
                sum+=down-peak;
            }   
        }
        return sum;
    }
};