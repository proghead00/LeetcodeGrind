class Solution {
public:
	vector<vector<int>> dd = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};

	void boundaryDFS(vector<vector<char>>& board, int x, int y, int r, int c) {

		board[x][y] = '#';

		for (int k = 0; k < 4; k++) {
			int xx = x + dd[k][0];
			int yy = y + dd[k][1];

			// NB: xx and NOT x:
			if (xx >= 0 and xx < r and yy >= 0 and yy < c and board[xx][yy] != 'X' and board[xx][yy] != '#')
				boundaryDFS(board, xx, yy, r, c);
		}
	}

	void solve(vector<vector<char>>& board) {
		int r = board.size();
		int c = board[0].size();

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (i == 0 or j == 0 or i == r - 1 or j == c - 1) {
					if (board[i][j] == 'O')
						boundaryDFS(board, i, j, r, c);
				}
			}
		}

		// now, all the boundary Os are turned into #s

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (board[i][j] == 'O')
					board[i][j] = 'X';
			}
		}

		// re-convert #s to Os
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (board[i][j] == '#')
					board[i][j] = 'O';
			}
		}
	}

};
