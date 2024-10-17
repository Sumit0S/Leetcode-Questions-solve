class Solution {
public:

    int maximumSwap(int num)
    {
        string s = "";
        while(num > 0) {
            s += (num % 10+'0');
            num = num / 10;
        }
        reverse(s.begin(),s.end());

        for(int i=0; i<s.length(); i++){
            int maxi=i;
            for(int j=i+1; j<s.length(); j++){
                if(s[i]<s[j] and s[maxi]<=s[j]){
                    maxi=j;
                }
            }
            if(i!=maxi){
                swap(s[i],s[maxi]);
                break;
            }
        }
        int num2 = stoi(s);
        return num2;
    }
};