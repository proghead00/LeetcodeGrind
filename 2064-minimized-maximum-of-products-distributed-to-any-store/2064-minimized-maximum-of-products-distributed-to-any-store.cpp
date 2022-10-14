class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1;
        int h = *max_element(quantities.begin(), quantities.end());
            
        int ans = 0;
        
        while (l <= h) {
            int mid = l + (h - l) / 2;

            int cnt = 0;
            for (int x : quantities) {
                cnt += x / mid;
                if (x % mid) cnt++;
            }

            // if (cnt <= n) return mid;
            if (cnt <= n) ans = mid, h = mid - 1;
            else l = mid + 1;
        }
        
        return ans;
    }
};