class Solution {
public:
  int numFactoredBinaryTrees(vector<int>& arr) {

    int mod = 1e9 + 7;

    unordered_map<long long, long long> mp;
    sort(arr.begin(), arr.end());

    int n = arr.size();
    for (int i = 0; i < n; i++)
      mp[arr[i]] = 1;

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {

        int cur = arr[i] / arr[j];

        if (cur * arr[j] == arr[i] and mp.count(cur)) {
          mp[arr[i]] += mp[cur] * mp[arr[j]];

        }
      }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) sum = (sum + mp[arr[i]]) % mod;
    return sum;
  }
};