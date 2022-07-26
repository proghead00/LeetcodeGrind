class Solution {
public:
    // bits(num1 OR num2) + bits(num1 AND num2) = bits(num1) + bits(num2)

    long long countExcellentPairs(vector<int>& nums, int k) {
        // to get unique value used unordered set
        set<int> s(nums.begin(), nums.end());


        // store the count of set bits in s, and store in v
        vector<int> v;
        for (auto pp : s) {
            int setbits = __builtin_popcountll(pp);
            v.push_back(setbits);
        }

        sort(v.begin(), v.end());

        long long ans = 0;
        for (int i = 0; i < v.size(); i++) {
            // find the lower bound of k-v[i] to know how many pairs it will form from that position
            auto it = lower_bound(v.begin(), v.end(), k - v[i]);
            ans += (v.end() - it);
        }
        return ans;
    }
};