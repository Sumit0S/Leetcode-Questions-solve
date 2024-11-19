class Solution {
public:

    int firsccc(vector<int>& arr, int k){
        int low=0;
        int high=arr.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==k){
                ans=mid;
            }
            if(arr[mid]>=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }

    int lastoccurance(vector<int>& arr, int k){
        int low=0;
        int high=arr.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==k){
                ans=mid;
            }
            if(arr[mid]<=k){
                low=mid+1;
            }
            else{
                high=mid-1;
                
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& arr, int k) {
        int firoc=firsccc(arr,k);
        int lastoc=lastoccurance(arr,k);
        vector<int> v;
        v.push_back(firoc);
        v.push_back(lastoc);
        return v;
    }
};