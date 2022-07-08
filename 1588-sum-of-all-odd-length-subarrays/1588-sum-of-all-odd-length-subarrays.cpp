class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            int s = n - i;
            int e = i + 1;

            int allSubarrFromThere = e * s;

            int oddSubarrays = allSubarrFromThere / 2;
            if (allSubarrFromThere & 1)  oddSubarrays++;

            ans += oddSubarrays * arr[i];
        }

        return ans;
    }
};