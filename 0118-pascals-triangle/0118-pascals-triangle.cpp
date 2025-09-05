class Solution {
public:

    void creating(vector<vector<int>> &ans,int num){
        vector<int> temp(num,1);
        if(num==1){
            ans.push_back(temp);
            return;
        }
        vector<int> v=ans.back();
        for(auto it:v){
            cout<<it<<" ";
        }
        cout<<endl;
        for(int i=0; i<num-1; i++){
            if(i>0 and i<num){
                int ans=v[i-1]+v[i];
                temp[i]=ans;
            }
        }
        ans.push_back(temp);

    }
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans;

        for(int i=1; i<=numRows; i++){
            creating(ans,i);
        }
        return ans;
    }
};