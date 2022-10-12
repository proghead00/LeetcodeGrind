class Solution {
public:

    bool help(vector<int>& weights, int days, int mid) {
        // check the sum on the go and partition when required

        int sum = 0;
        int d = 1;

        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if (sum > mid) {
                sum = weights[i]; // start from the next (partition)
                d++;
            }
        }
        if (d <= days) return true;
        else return false;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int h = accumulate(weights.begin(), weights.end(), h);

        int ans = 0;
        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (help(weights, days, mid)) {
                ans = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }

        return ans;

    }
};