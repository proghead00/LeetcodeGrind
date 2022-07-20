
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();

        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq;

        for (int i = 0; i < n - 1; i++)
            pq.push({(double) arr[i] / arr[n - 1], {i, n - 1}});

        int i, j;

        while (k--) {
            auto tp = pq.top();
            pq.pop();

            i = tp.second.first;
            j = tp.second.second;

            if (i < j - 1) pq.push({(double) arr[i] / arr[j - 1], {i, j - 1}});
        }

        return {arr[i], arr[j]};
    }
};

