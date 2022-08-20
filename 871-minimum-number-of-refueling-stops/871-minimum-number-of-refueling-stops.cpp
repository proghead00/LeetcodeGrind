class Solution {
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

		// initial case
		// if (startFuel < stations[0][0]) return -1;

        priority_queue<int> pq;
		int curFuel = startFuel;

		int ans = 0, i = 0;

		while (curFuel < target) {
			while (i < stations.size() and stations[i][0] <= curFuel) {
				pq.push(stations[i][1]);
				i++;
			}

			if (pq.empty()) return -1; // also handles the initial case

			curFuel += pq.top();
			pq.pop();
			ans++;
		}

		return ans;
	}
};