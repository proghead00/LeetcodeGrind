class Solution {
public:

	bool cycle(vector<vector<int>>& gr, vector<int>& dfsVis, vector<int>& vis, int node) {

		vis[node] = 1;
		dfsVis[node] = 1;

		for (auto x : gr[node]) {
			if (!vis[x]) {
                
                // make sure to pass x as the current node 
				if (cycle(gr, dfsVis, vis, x))
					return true;
			}

			else if (vis[x] and dfsVis[x])
				return true;
		}

		dfsVis[node] = 0;
		return false;
	}

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

		vector<vector<int>> gr(numCourses);

		vector<int> vis(numCourses);
		vector<int> dfsVis(numCourses);

		for (auto x : prerequisites)
			gr[x[0]].push_back(x[1]);

		for (int i = 0; i < numCourses; i++) {
			if (!vis[i]) {
				if (cycle(gr, dfsVis, vis, i))
					return false;
			}
		}

		return true;
	}

};