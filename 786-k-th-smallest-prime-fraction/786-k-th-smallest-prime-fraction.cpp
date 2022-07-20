class Solution {
public:
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
    priority_queue<pair<double, pair<int, int>>> pq; // fractiontion, (i, j)

    for (int i = 0; i < arr.size() - 1; i++) {
      for (int j = i + 1; j < arr.size(); j++) {

        double fraction = (double)arr[i] / (double)arr[j];

        if (pq.size() < k) {
          pq.push({fraction, {arr[i], arr[j]}});
        } else {
          if (pq.top().first >
              fraction) { // since min heap, so if top is greater, then pop
            pq.pop();
            pq.push({fraction, {arr[i], arr[j]}});
          }
        }
      }
    }
    return {pq.top().second.first, pq.top().second.second};
  }
};
