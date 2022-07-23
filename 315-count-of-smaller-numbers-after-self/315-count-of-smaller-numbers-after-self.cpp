class Solution {
public:

    void join(int s, int e, int mid, vector<int> &cnt, vector<pair<int, int>> &numsPairs) {

        int i = s, j = mid + 1;

        vector<pair<int, int>> tempPairs(e - s + 1);

        int k =  0;
        while (i <= mid and j <= e) {
            if (numsPairs[i].first <= numsPairs[j].first) {
                tempPairs[k++] = numsPairs[j++];
            }
            else {
                cnt[numsPairs[i].second] += e - j + 1;
                tempPairs[k++] = numsPairs[i++];
            }

        }

        while (i <= mid) tempPairs[k++] =  numsPairs[i++];

        while (j <= e) tempPairs[k++] = numsPairs[j++];

        for (int kk = s; kk <= e; kk++) numsPairs[kk] = tempPairs[kk - s];
    }

    void split(int s, int e, vector<int> &cnt, vector<pair<int, int>> &numsPairs) {
        if (s >= e) return; // since I need to split UNTIL there's only one element that remains

        int mid = (s + e) / 2 ;
        split(s, mid, cnt, numsPairs);
        split(mid + 1, e, cnt, numsPairs);

        join(s, e, mid, cnt, numsPairs);
    }

    vector<int> countSmaller(vector<int>& nums) {

        vector<pair<int, int>> numsPairs(nums.size());
        vector<int> cnt(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++)
            numsPairs[i] = {nums[i], i}; // need i for storing values in cnt vector

        split(0, nums.size() - 1, cnt, numsPairs);

        return cnt;
    }
};