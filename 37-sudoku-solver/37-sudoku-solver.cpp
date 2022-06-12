class Solution {
public:
  bool valid(vector<vector<char>> &board, int r, int c, char choice) {

    for (int i = 0; i < 9; i++) {

      if (board[i][c] == choice)
        return false;

      if (board[r][i] == choice)
        return false;

      int rrr = 3 * (r / 3) + i / 3;
      int ccc = 3 * (c / 3) + i % 3;

      if (board[rrr][ccc] == choice)
        return false;
    }

    return true;
  }

    
  bool fill(vector<vector<char>> &board) {
    for (int r = 0; r < board.size(); r++) {
      for (int c = 0; c < board[0].size(); c++) {

        if (board[r][c] == '.') {
          for (char choice = '1'; choice <= '9'; choice++) {

            if (valid(board, r, c, choice)) {
              board[r][c] = choice;
              if (fill(board))
                return true;
              else
                board[r][c] = '.';
            }
          }
          return false;
        }
      }
    }
    return true;
  }
    
  void solveSudoku(vector<vector<char>> &board) { fill(board); }
};
