class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        vector<int> ans(n);
        stack<pair<int, int>> stk;

        for (int i = 0; i < n; i++) {

            while (!stk.empty() and stk.top().first < temperatures[i]) {
                ans[stk.top().second] = (i - stk.top().second);
                stk.pop();
            }

            stk.push({temperatures[i], i});
        }

        return ans;

    }
};

