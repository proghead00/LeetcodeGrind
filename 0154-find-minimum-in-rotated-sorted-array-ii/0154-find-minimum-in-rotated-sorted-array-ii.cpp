class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0, h = num.size() - 1;
        while (l < h) {
            int mid = l + (h - l) / 2;

            if (num[mid] > num[h]) l = mid + 1;

            else if (num[mid] < num[h]) h = mid; // why not mid - 1? since the min might be at mid itself

            else h--; // when we get the equal case

        }

        return num[h];
    }
};