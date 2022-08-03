class Solution {
public:

    bool valid(vector<vector<char>> &board, int r, int c, char choice) {

        for (int i = 0; i < 9; i++) {

            // if the same no. is present in that col
            if (board[i][c] == choice) {
                return false;
            }

            // if present in that row
            if (board[r][i] == choice) {
                return false;
            }

            // if present in the subgrid
            int rrr = 3 * (r / 3) + i / 3;
            int ccc = 3 * (c / 3) + i % 3;

            if (board[rrr][ccc] == choice)
                return false;
        }

        return true;
    }

    bool fill(vector<vector<char>> &board) {
        // try to place 1-9

        // search for a blank spot to be filled up
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {

                // blank spot found
                if (board[r][c] == '.') {

                    // try to fill
                    for (char choice = '1'; choice <= '9'; choice++) {

                        if (valid(board, r, c, choice)) { // if I can fill (for the time)

                            // fill it
                            board[r][c] = choice;

                            // now ask recursion to temme if it's a correct fill, and whether there's no issue in the "future"
                            if (fill(board))
                                return true;
                            else
                                // backtrack, so remove that char and try to fill other char
                                board[r][c] = '.';
                        }
                    }

                    // everything's filled up and matrix is traversed
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        fill(board);
    }
};
