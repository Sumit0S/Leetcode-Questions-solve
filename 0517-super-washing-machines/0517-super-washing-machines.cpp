class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int sum = accumulate(machines.begin(), machines.end(), 0);
        if (sum % n != 0) return -1;
        
        int target = sum / n;
        int maxMoves = 0, imbalance = 0;
        
        for (int load : machines) {
            imbalance += load - target;
            maxMoves = max(maxMoves, max(abs(imbalance), load - target));
        }
        
        return maxMoves;
    }
};
