class Solution {
public:
    bool dfs(int cur, int par, vector<vector<int>>& gr, vector<bool>& vis) {
        vis[cur] = 1;

        for (auto nbr : gr[cur]) {
            if (!vis[nbr]) {
                if (dfs(nbr, cur, gr, vis)) return true;
            }
            else if (nbr != par)
                return true;
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> gr(n + 1);
        vector<bool> vis(n + 1, 0);

        for (auto e : edges) {
            fill(begin(vis), end(vis), 0);
            gr[e[0]].push_back(e[1]);
            gr[e[1]].push_back(e[0]);

            if (dfs(e[0], -1, gr, vis))
                return e;
        }

        return {};
    }

};