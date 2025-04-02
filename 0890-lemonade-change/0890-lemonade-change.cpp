class Solution {
public:
    bool lemonadeChange(vector<int>& arr) 
    {
        int track5=0;
        int track10=0;

        for(int i=0; i<arr.size(); i++){
            if(arr[i]==5){
                track5++;
            }
            else{
                if(arr[i]==10){
                    if(track5>0){
                        track5--;
                        track10++;
                    }
                    else{
                        return false;
                    }
                    
                }
                else{
                    if(track10>0 and track5>0){
                        track5--;
                        track10--;
                    }
                    else if(track5>=3){
                        track5-=3;
                    }
                    else{
                        return false;
                    }
                    
                }
            }
        }
        return true;
    }
};