class Solution {
public:
  int minSetSize(vector<int> &arr) {
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); ++i) {
      mp[arr[i]]++;
    }

    vector<int> vals;
    for (auto &x : mp) {
      vals.push_back(x.second);
    }

    sort(vals.begin(), vals.end(), greater<int>());

    int cnt = 0;
    int i = 0;
    int n = arr.size();

    for (int i = 0; i < arr.size(); i++) {
      n -= vals[i];
      if (n <= arr.size() / 2) {
        cnt++;
        break;
      }
      cnt++;
    }

    return cnt;
  }
};
