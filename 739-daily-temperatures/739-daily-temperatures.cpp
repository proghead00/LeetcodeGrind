class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {

        int n = temperatures.size() - 1;
        vector<int> ans;
        ans.push_back(0);

        stack<pair<int, int>> s; // temp, i
        s.push({temperatures[n], n});

        int i = n - 1;

        while (i >= 0 and !s.empty()) {

            pair<int, int> x = {temperatures[i], i};

            if (temperatures[i] < s.top().first) ans.push_back(1);

            else {

                while (s.size() and temperatures[i] >= s.top().first) s.pop();

                if (s.empty()) ans.push_back(0);
                else {
                    // distance between current temp (i) and the next greater
                    int dist = s.top().second - i;
                    ans.push_back(dist);
                }
            }

            s.push(x);
            i--;
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};
