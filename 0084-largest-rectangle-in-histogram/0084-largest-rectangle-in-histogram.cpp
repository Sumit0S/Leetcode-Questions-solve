class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n=heights.size();
        stack<int> st;
        int maxArea=0;
        int pse=-1;
        int nse=n;
        for(int i=0; i<n; i++){
            while(!st.empty() and heights[i]<heights[st.top()])
            {
                nse=i;
                int element=heights[st.top()];
                st.pop();
                pse=st.empty()?-1:st.top();
                maxArea=max(maxArea,element*(nse-pse-1));       
            }
            st.push(i);
        }
        nse=n;
        while(!st.empty()){
            int el=st.top();
            st.pop();
            pse=st.empty()?-1:st.top();
            maxArea=max(maxArea,heights[el]*(nse-pse-1));
        }
        return maxArea;
    }
};