class Solution {
public:
    int maxDiff(int num) {
        string n = to_string(num);

        int largest_ind = -1;
        int smallest_ind = -1;

        for (int i = 0; i < n.length(); i++) {
            if (n[i] != '9' && largest_ind == -1) {
                largest_ind = i;
            }
            if (n[i] != '1' && smallest_ind == -1 && n[i] != '0') {
                smallest_ind = i;
            }
        }

        string maxi = n;
        string mini = n;

        if (largest_ind != -1) {
            char to_replace = n[largest_ind];
            for (int i = 0; i < maxi.length(); i++) {
                if (maxi[i] == to_replace) {
                    maxi[i] = '9';
                }
            }
        }

        if (smallest_ind != -1) {
            char to_replace = n[smallest_ind];
            for (int i = 0; i < mini.length(); i++) {
                if (mini[i] == to_replace) {
                    mini[i] = (smallest_ind == 0) ? '1' : '0';
                }
            }
        }

        return stoi(maxi) - stoi(mini);
    }
};
