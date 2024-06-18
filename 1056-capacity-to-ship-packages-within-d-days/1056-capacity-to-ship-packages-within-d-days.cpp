class Solution {
public:

    int calculatedays(vector<int> weights,int cap)
    {
        int days = 1; //First day.
        int load = 0;
        int n = weights.size(); //size of array.
        for(int i=0; i<n; i++){
            if(load+weights[i]>cap){
                days+=1;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int min_weight=0;
        int max_weight=0;
        for(int i=0; i<weights.size(); i++)
        {
            min_weight=max(min_weight,weights[i]);
            max_weight+=weights[i];
        }

        int low=min_weight;
        int high=max_weight;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(calculatedays(weights,mid)<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};