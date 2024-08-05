class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        
        vector<int> st;
        int n=arr.size();
         
        for(int i=0;i<n;i++){
            
            if(arr[i]>0)
              st.push_back(arr[i]);
              else{
                  while(!st.empty() and st.back()>0 and  st.back()<abs(arr[i]))
                           st.pop_back();
              
                  
                  if(!st.empty() and st.back()==abs(arr[i]))
                      st.pop_back();
                     else if(st.empty() or (st.back()<0))   // pointing about this condition
                         st.push_back(arr[i]);                 
              }
                    
        }
        
        return st;
    }
};