class Solution {
public:
    vector<int> adj[205];

    void dfs(vector<bool>&vis, int cur) {
        vis[cur] = 1;
        for (auto nbr : adj[cur]) {
            if (!vis[nbr])
                dfs(vis, nbr);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> visited(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1)
                    adj[i].push_back(j);
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(visited, i);
                cnt++;
            }
        }

        return cnt;
    }
};