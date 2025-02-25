class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize)
    {
      if (hand.size() % groupSize != 0)
      {
            return false; // If total cards are not a multiple of groupSize, return false
      }
        map<int,int> mp;

        for(int it:hand){
            mp[it]++;
        }

      
        for (auto it = mp.begin(); it != mp.end(); ){
            int val=it->first;
            for(int i=0; i<groupSize; i++){
                if (mp[val + i] == 0) {
                    return false; // If a card is missing, return false
                }
                mp[val+i]--;
                if(mp[val+i]==0)
                {
                    mp.erase(val+i);
                }
            }
            it = mp.begin();
        }
        return true;
    }
};