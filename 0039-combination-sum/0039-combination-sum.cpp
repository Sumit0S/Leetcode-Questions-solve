class Solution {
public:
    void combinations(vector<int> &candidates,int target,int index,vector<vector<int> > &ans,vector<int> &output)
    {
        if(index>=candidates.size()){
            if(target==0){
                ans.push_back(output);
            }
            return;
        }
        combinations(candidates,target,index+1,ans,output);
        if(target>=candidates[index]){
        int a=candidates[index];
        output.push_back(a);
        combinations(candidates,target-a,index,ans,output);
         output.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        combinations(candidates,target,0,ans,output);
        return ans;
    }
};