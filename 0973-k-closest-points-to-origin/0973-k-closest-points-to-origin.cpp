class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue <pair<int, pair<int, int>>> pq; // dist, {x, y}

        for (auto p : points) {
            int x = p[0];
            int y = p[1];

            pq.push({x * x + y * y, {x, y}});
           
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            auto x = pq.top().second;

            vector<int> temp(2);
            temp[0] = x.first;
            temp[1] = x.second;

            ans.push_back(temp);
            pq.pop();
        }

        return ans;
    }
};