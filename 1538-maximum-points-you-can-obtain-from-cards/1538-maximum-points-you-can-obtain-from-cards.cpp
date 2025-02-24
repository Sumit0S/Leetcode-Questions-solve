class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k)
    {
        int lsum=0;
        int rsum=0;
        

        for(int i=0; i<k; i++){
            lsum+=cardPoints[i];
        }
        int ans=lsum;
        int n=cardPoints.size()-1;
        while(lsum!=0){
            lsum=lsum-cardPoints[k-1];
            k--;
            rsum+=cardPoints[n];
            n--;
            int cur=lsum+rsum;
            ans=max(ans,cur);
        }
        return ans;
    }
};