class Solution {
public:
  // directions: (\U0001f449) 0 | (\U0001f447) 1 | (\U0001f448) 2 | (\U0001f446) 3

  // direction update after each ```while``` iteration:
  // dir = (dir+1) % 4
  // example: after dir == 0 is done,
  // dir = (0+1) % 4 = 1 (for next iteration)

  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int top = 0, right = matrix[0].size() - 1;
    int bottom = matrix.size() - 1, left = 0;

    vector<int> ans;
    int dir = 0;

    int i;

    while (top <= bottom and left <= right) {
      // \U0001f449
      if (dir == 0) {
        for (i = left; i <= right; i++) {
          ans.push_back(matrix[top][i]); // row is fixed here
        }
        top++;
      }

      // \U0001f447
      else if (dir == 1) {
        // top has already come one step down
        for (i = top; i <= bottom; i++) {
          ans.push_back(matrix[i][right]);
        }
        right--;
      }

      // \U0001f448
      else if (dir == 2) {
        // right has already come one tep left
        for (i = right; i >= left; i--) {
          ans.push_back(matrix[bottom][i]);
        }
        bottom--;
      }
      // \U0001f446
      else if (dir == 3) {
        for (i = bottom; i >= top; i--) {
          ans.push_back(matrix[i][left]);
        }
        left++;
      }

      dir = (dir + 1) % 4;
    }

    return ans;
  }
};
