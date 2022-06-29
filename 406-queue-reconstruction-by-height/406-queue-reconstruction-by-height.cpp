class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    int n = people.size();
    vector<vector<int>> ans;

    /*
  1. sort descending by height and insert
  2. if height is same, sort by increasing of 1st index
  3. if element is already present, insert the smaller one before, cuz before
  that a larger number will be present
  */

    sort(people.begin(), people.end(),
         [](const vector<int> &a, const vector<int> &b) {
           if (a[0] == b[0]) {
             return a[1] < b[1];
           }
           return a[0] > b[0];
         });

    for (int i = 0; i < n; i++) {
      int idx = people[i][1];
      ans.insert(ans.begin() + idx, people[i]); // inserting that eleement at the desired index
    }
    return ans;
  }
};
