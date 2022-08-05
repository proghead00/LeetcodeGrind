class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hrs) {
        int l = 1;
        int h = *max_element(piles.begin(), piles.end());

        while (l < h) {

            int k = l + (h - l) / 2;

            long long int sum = 0;
            for (auto p : piles) {
                sum += ceil((double) p / k);
            }

            if (sum <= hrs) h = k;
            else l = k + 1;
        }

        return l;
    }
};