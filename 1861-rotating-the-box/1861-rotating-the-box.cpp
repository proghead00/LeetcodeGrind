class Solution {

public:
  vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
    int m = box.size();
    int n = box[0].size();

    vector<vector<char>> box2(n, vector<char>(m, '.'));

    for (int i = 0; i < m; i++) {
      int last = n;
      for (int j = n - 1; j >= 0; j--) {
        if (box[i][j] == '#') {
          last--;
          box2[last][i] = '#';
        } else if (box[i][j] == '*') {
          last = j;
          box2[j][i] = '*';
        }
      }
    }
    for (int i = 0; i < n; i++) {
      reverse(box2[i].begin(), box2[i].end());
    }
    return box2;
  }
};
