class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        int ans = min(passengers[0] - 1, buses[buses.size() - 1]);

        int bb = 0, pp = 0;

        while (bb < buses.size() and pp < passengers.size()) {
            int cap = capacity;

            while (cap and pp < passengers.size() and passengers[pp] <= buses[bb]) {
                if (pp and passengers[pp] - passengers[pp - 1] > 1) {
                    ans = passengers[pp] - 1;
                }
                cap--;
                pp++;
            }
            if (cap) {
                if (pp and buses[bb] != passengers[pp - 1]) ans = buses[bb];
            }


            bb++;
        }

        if (bb != buses.size())
            ans = buses[buses.size() - 1];
        return ans;
    }

};