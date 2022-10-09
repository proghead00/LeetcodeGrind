class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, h = n - 1; // h = n - 1 (not h = n since max could be the last element in the array: l and h denote indices)

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (citations[mid] == n - mid) return citations[mid];
            else if (citations[mid] < n - mid) l = mid + 1;
            else h = mid - 1;
        }

        return n - l;
    }
};


