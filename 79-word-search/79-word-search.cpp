class Solution {
public:

    bool valid(int i, int j, int n, int m) {
        if (i >= 0 and i < n and j >= 0 and j < m) return true;
        return false;
    }

    bool help(vector<vector<char>>&board, string &word, int i, int j, int idx, int n, int m) {

        if (idx == word.size()) return true;

        if (!valid(i, j, n, m)) return false;

        if (board[i][j] != word[idx]) return false;

        char ch = board[i][j];
        board[i][j] = '!';

        bool up = help(board, word, i - 1, j, idx + 1, n, m);
        bool down = help(board, word, i + 1, j, idx + 1, n, m);
        bool left = help(board, word, i, j - 1, idx + 1, n, m);
        bool right = help(board, word, i, j + 1, idx + 1, n, m);

        if (up or down or left or right) return true;

        board[i][j] = ch;
        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (help(board, word, i, j, 0, n, m))
                    return true;

            }
        }
        return false;
    }
};