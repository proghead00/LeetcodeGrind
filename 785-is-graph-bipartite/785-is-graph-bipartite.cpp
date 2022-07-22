class Solution {
public:

    bool dfs(vector<vector<int>>& graph, vector<int> &colorVis, int cur, int parentColor) {

        colorVis[cur] = 1 - parentColor;

        for (auto x : graph[cur]) {

            if (colorVis[x] == -1) {
                if (dfs(graph, colorVis, x, colorVis[cur]) == false) return false;
            }

            else if (colorVis[x] == colorVis[cur])
                return false;
        }

        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colorVis(n, -1);

        for (int i = 0; i < n; i++) {
            if (colorVis[i] == -1) {
                if (!dfs(graph, colorVis, i, 0))
                    return false;
            }
        }

        return true;
    }
};