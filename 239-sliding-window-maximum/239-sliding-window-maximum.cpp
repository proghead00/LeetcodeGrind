
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        // calculate the first window before moving
        for (int i = 0; i < k; i++) {
            while (!dq.empty() and nums[i] >= nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        if (!dq.empty()) ans.push_back(nums[dq.front()]);

        for (int i = k; i < nums.size(); i++) {
            // case 1:
            while (!dq.empty() and dq.front() < (i - k + 1)) dq.pop_front();

            // case 2:
            while (!dq.empty() and nums[i] >= nums[dq.back()]) dq.pop_back();

            dq.push_back(i);

            // front() has the max element in the window
            if (!dq.empty()) ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};