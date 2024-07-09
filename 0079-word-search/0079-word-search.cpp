#include <vector>
#include <string>

class Solution {
public:
    bool is_this(int row, int col, std::vector<std::vector<char>>& board, std::string& word, int index) {
        if (index == word.length()) {
            return true;
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) {
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '#';  // Mark as visited

        bool found = is_this(row - 1, col, board, word, index + 1) ||
                     is_this(row + 1, col, board, word, index + 1) ||
                     is_this(row, col - 1, board, word, index + 1) ||
                     is_this(row, col + 1, board, word, index + 1);

        board[row][col] = temp;  // Unmark the cell

        return found;
    }

    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0] && is_this(i, j, board, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
