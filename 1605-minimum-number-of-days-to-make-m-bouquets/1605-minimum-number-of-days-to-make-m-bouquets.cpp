#pragma GCC optimize("Ofast","inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")

static int fast_io = []() 
{ 
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr); 
    return 0; 
}();

#ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif

class Solution {
public:
    bool possible(vector<int> bloomDay,int m ,int k , int day){
        int cnt=0;
        int noB=0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=day){
                cnt++;
            }
            else{
                noB+=(cnt/k);
                cnt=0;
            }
        }
        noB+=(cnt/k);
        return noB>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size(); //size of the array
        if (val > n) return -1;
        int low=0;
        int high=0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]>high){
                high=max(high,bloomDay[i]);
            }
            else{
                low=min(bloomDay[i],low);
            }
        }

        while(low<=high){
            long long mid= low+(high-low)/2;

            if(possible(bloomDay,m,k,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};