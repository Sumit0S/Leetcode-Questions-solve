class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        
        string temp = s + s;
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            bool found = true;
            for (int j = 0; j < n; ++j) {
                if (temp[i + j] != goal[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            }
        }
        
        return false;
    }
};
