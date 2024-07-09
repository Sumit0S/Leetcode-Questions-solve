class Solution {
public:

    bool is_this(int row,int col,vector<vector<char>>& board,string word,string curr){
        if (curr.length() >= word.length()) {
            return true;
        }
        if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && board[row][col] == word[curr.length()]) {
            curr += board[row][col];
            char temp = board[row][col];
            board[row][col] = '#'; // Mark as visited

            bool found = is_this(row - 1, col, board, word, curr) ||
                         is_this(row + 1, col, board, word, curr) ||
                         is_this(row, col - 1, board, word, curr) ||
                         is_this(row, col + 1, board, word, curr);

            board[row][col] = temp; // Unmark the cell
            return found;
        }
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {

    string curr="";
      for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j]==word[0]){
                if(is_this(i,j,board,word,curr)){
                    return true;
                }
                
            }
        }
      }
      return false;
    }
};