class Solution {

  int mx = INT_MIN;

public:

  void help(int numArrows, vector<int> &aliceArrows, int idx, vector<int>&temp, vector<int> &bob) {

    if (idx == 12) {
      int sum = 0;
      for (int i = 0; i < 12; i++) {
        if (temp[i])
          sum += i;
      }

      // dump the rest of the arrows remaining to temp[0]
      if (numArrows) {
        temp[0] += numArrows;
      }

      if (sum > mx) {
        mx = sum;
        bob = temp;
      }

      temp[0] -= numArrows;

      return;
    }

    // take
    if (numArrows > aliceArrows[idx]) {
      temp[idx] = aliceArrows[idx] + 1;
      numArrows -= aliceArrows[idx] + 1;
      help(numArrows, aliceArrows, idx + 1, temp, bob);
      temp[idx] = 0;
      numArrows += aliceArrows[idx] + 1;
    }

    // don't take
    help(numArrows, aliceArrows, idx + 1, temp, bob);

  }

  vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
    vector<int> temp(12, 0);
    vector<int> bob;
    help(numArrows, aliceArrows, 0, temp, bob);

    return bob;
  }
};