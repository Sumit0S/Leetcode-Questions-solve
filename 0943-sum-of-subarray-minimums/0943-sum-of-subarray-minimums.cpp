class Solution {
public:

vector<int> presmaler(vector<int>& arr)
   
{

        stack<int> st;
        vector<int> v(arr.size());
        for(int i=0; i<arr.size(); i++)
        {
            while(!st.empty() and arr[i]<arr[st.top()])
            {
                st.pop();
            }
            v[i]=st.empty()?-1:st.top();
            st.push(i); 
        }
        return v;

}

vector<int> nextsmaler(vector<int>& arr)
   
{

        stack<int> st;
        vector<int> v(arr.size());
        for(int i=arr.size()-1; i>=0; i--)
        {
            while(!st.empty() and arr[i]<=arr[st.top()])
            {
                st.pop();
            }
            v[i]=st.empty()?arr.size():st.top();
            st.push(i); 
        }
        return v;

}

int sumSubarrayMins(vector<int>& arr) 
    {
        long long mod=1000000007;
        int n=arr.size();
        vector<int> a = presmaler(arr);
        vector<int> b = nextsmaler(arr);
        long long total=0;

        for(int i=0; i<n; i++){
            cout<<b[i];
        }
        for(int i=0; i<n; i++){
            int left=i-a[i];
            int right=b[i]-i;
            total = (total + arr[i] * 1LL * left * right % mod) % mod;
        }
        return static_cast<int>(total);
    }
};