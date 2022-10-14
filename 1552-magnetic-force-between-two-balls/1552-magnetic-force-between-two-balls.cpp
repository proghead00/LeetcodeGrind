class Solution {
public:

    bool help(vector<int> position, int m, int mid) {
        int cnt = 1;
        int prev = position[0];
        for (int i = 1 ; i < position.size() ; i++) {
            if (position[i] - prev >= mid) {
                cnt++;
                prev = position[i];
            }
        }
        return cnt >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        
        sort(position.begin(), position.end());
        
        int l = 1;
        int h = 1e9 + 10;
        int ans;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (help(position, m, mid)) {
                ans = mid;
                l = mid + 1;
            }
            else h = mid - 1;
        }

        return ans;
    }
};