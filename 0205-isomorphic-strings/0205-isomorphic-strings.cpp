class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> map1;
        map<char, char> map2;

        for(int i=0; i<s.size(); i++){
        char c1 = s[i];
        char c2 = t[i];

        // Check if there is already a mapping for c1
        if (map1.find(c1) != map1.end()) {
            // If the current mapping does not match the previous mapping, return false
            if (map1[c1] != c2) {
                return false;
            }
        } else {
            // Otherwise, create a new mapping from c1 to c2
            map1[c1] = c2;
        }
        if (map2.find(c2) != map2.end()) {
            // If the current mapping does not match the previous mapping, return false
            if (map2[c2] != c1) {
                return false;
            }
        } else {
            // Otherwise, create a new mapping from c2 to c1
            map2[c2] = c1;
        }

        }
        return true;
    }
};