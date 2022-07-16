class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> s;
        int n = heights.size();

        vector<int> left(n), right(n);

        // left to right (would check upon left index range)
        for (int i = 0; i < heights.size(); i++) {

            if (s.empty()) left[i] = 0;
            else {
                while (s.size() and heights[s.top()] >= heights[i]) {
                    s.pop();
                }
                if (s.empty()) left[i] = 0;
                else left[i] = s.top() + 1;
            }

            s.push(i);
        }

        // clear the stack to re-use
        while (!s.empty()) s.pop();

        int last = n - 1;

        // right to left (would check upon right index range)
        for (int i = heights.size() - 1; i >= 0; i--) {

            if (s.empty()) right[i] = last;

            else {
                while (s.size() and heights[s.top()] >= heights[i]) {
                    s.pop();
                }
                if (s.empty()) right[i] = last;
                else right[i] = s.top() - 1;
            }

            s.push(i);
        }

        int mx = 0;
        for (int i = 0; i < heights.size(); i++) {
            int curArea = heights[i] * (right[i] - left[i] + 1);
            mx = max(mx, curArea);
        }

        return mx;
    }

};