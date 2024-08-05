class Solution {
    void removeLeadingSpace(string &s, int &i){
        while(i < s.size() && s[i] == ' ') i++;
    }
public:
    int myAtoi(string s) {
        if(s.size() == 0) return 0;
        int i = 0;
        removeLeadingSpace(s, i);
        if(i == s.size()) return 0;
        long long mini = INT_MIN, maxi = INT_MAX, ans = 0, sign = 1;
        if(s[i] == '-'){
            sign *= -1;
            i++;
        }else if(s[i] == '+') i++;
        for(; i<s.size(); i++){
            if(s[i] < '0' || s[i] > '9') return ans;
            ans = ans * 10 + (sign * (s[i] - '0'));
            if(ans <= mini) return mini;
            if(ans >= maxi) return maxi;
        }
        return ans;
    }
};