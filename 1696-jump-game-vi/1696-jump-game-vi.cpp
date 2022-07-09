class Solution {
public:

    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq;
        vector<int> dp(n);

        dp[n - 1] = nums[n - 1]; // can only take at last idx

        dq.push_back(n - 1);


        for (int i = n - 2; i >= 0; i--) {
            
            // order of the statements matter
            while (!dq.empty() and dq.front() - i > k) dq.pop_front();
            dp[i] = nums[i] + dp[dq.front()];
            
            while (!dq.empty() and dp[dq.back()] <= dp[i]) dq.pop_back();
            dq.push_back(i);
        }
        return dp[0];
    }
};