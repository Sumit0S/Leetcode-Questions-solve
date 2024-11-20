class Solution {
public:

    int findmax(vector<int>& weights){
        int maxi=INT_MIN;
        for(auto it:weights){
            maxi=max(maxi,it);
        }
        return maxi;
    }
    int findsum(vector<int>& weights){
        int n_sum=0;
        for(auto it:weights){
            n_sum+=it;
        }
        return n_sum;
    }
    bool is_(vector<int>& weights, int days,int w){
        int no_days=1;
        int sumi=0;
        for(int i=0; i<weights.size(); i++){
            sumi+=weights[i];
            if(sumi>w){
                sumi=weights[i];
                no_days+=1;
            }
        }

        return days>=no_days;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int low=findmax(weights);
        int high=findsum(weights);

        while(low<=high){
            int mid=low+(high-low)/2;

            if(is_(weights,days,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};