class Solution {
public:
    int findmax(vector<int>& bloomDay){
        int maxi=INT_MIN;
        for(auto it:bloomDay){
            maxi=max(maxi,it);
        }
        return maxi;
    }

    int findmin(vector<int>& bloomDay){
        int maxi=INT_MAX;
        for(auto it:bloomDay){
            maxi=min(maxi,it);
        }
        return maxi;
    }

    bool is_m(vector<int>& bloomDay, int m, int k,int mid){
        int cnt=0;
        int total_val=0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }
            else{
                total_val+=cnt/k;
                cnt=0;
            }
        }
        total_val+=cnt/k;
        return total_val>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        long long int v=k*1LL*m*1LL;
         if(bloomDay.size()<v){
            return -1;
         }
         int low=findmin(bloomDay);
         int high=findmax(bloomDay);

         while(low<=high){
            int mid=low+(high-low)/2;
            bool is_=is_m(bloomDay,m,k,mid);
            if(is_){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
         }
         return low;
    }
};