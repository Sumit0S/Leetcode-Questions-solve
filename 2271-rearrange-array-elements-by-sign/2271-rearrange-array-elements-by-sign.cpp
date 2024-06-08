class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        vector<int> pos;
  vector<int> neg;
  int n=nums.size();
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){
      
      if(nums[i]>0) pos.push_back(nums[i]);
      else neg.push_back(nums[i]);
  }
  
  // If positives are lesser than the negatives.
  if(pos.size() < neg.size()){
      
    // First, fill array alternatively till the point 
    // where positives and negatives ar equal in number.
    for(int i=0;i<pos.size();i++){
      
      nums[2*i] = pos[i];
      nums[2*i+1] = neg[i];
    }
    
    // Fill the remaining negatives at the end of the array.
    int index = pos.size()*2;
    for(int i = pos.size();i<neg.size();i++){
        
        nums[index] = neg[i];
        index++;
    }
  }
  
  // If negatives are lesser than the positives.
  else{
      
      // First, fill array alternatively till the point 
      // where positives and negatives ar equal in number.
      for(int i=0;i<neg.size();i++){
      
      nums[2*i] = pos[i];
      nums[2*i+1] = neg[i];
  }
    
    // Fill the remaining positives at the end of the array.
    int index = neg.size()*2;
    for(int i = neg.size();i<pos.size();i++){
        
        nums[index] = pos[i];
        index++;
    }
  }
    return nums;
    }
};