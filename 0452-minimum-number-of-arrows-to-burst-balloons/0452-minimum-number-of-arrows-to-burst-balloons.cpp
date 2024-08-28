class Solution {
public:

    bool static comparator(const vector<int>& a, const vector<int>& b) {
        if (a[1] < b[1]) {
            return true;
        } else if (a[1] > b[1]) {
            return false;
        } else {
            // If the first elements are equal, compare the second elements
            return a[0] < b[0];
        }
    }
    int findMinArrowShots(vector<vector<int>>& points)
    {
        sort(points.begin(),points.end(),comparator);

        int curr_val=points[0][1];
        for( auto val : points){
            cout<<val[0]<<" "<<val[1]<<endl;
        }
        int cnt=1;
        for( auto val : points){
            if(curr_val>=val[0]){
                continue;
            }
            else{
               curr_val=max(curr_val,val[1]);
               cnt++;  
            }
        }
        return cnt;
    }
};