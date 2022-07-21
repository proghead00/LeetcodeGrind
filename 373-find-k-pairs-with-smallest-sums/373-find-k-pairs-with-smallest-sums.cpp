class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

    priority_queue<pair<int, pair<int, int>>> pq; // will be sorted by sum; pair{sum, {element1, element2}}

    int n = nums1.size(), m = nums2.size();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {

        int sum = nums1[i] + nums2[j];

        if (pq.size() < k)
          pq.push({ sum, {nums1[i], nums2[j]}});

        else if (pq.top().first > sum) { // since I am maintaing a max heap, top gives me the max
          pq.pop();
          pq.push({sum, {nums1[i], nums2[j]}});
        }

        else break;

      }
    }

    vector<vector<int>> ans;
    while (!pq.empty()) {
      ans.push_back({pq.top().second.first, pq.top().second.second});
      pq.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};