class Solution {
public:
  long long cnt = 0;

  void dfs(int cur, vector<vector<int>> &adj, vector<int> &visited) {
    visited[cur] = 1;
    cnt++;
      
    for (auto &x : adj[cur]) {
      if (visited[x])
        continue;
      
        dfs(x, adj, visited);
    }
  }

  long long countPairs(int n, vector<vector<int>> &edges) {
    
    vector<vector<int>> adj(n);
      
    for (auto &e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    vector<int> visited(n, 0);
    long long ans = 0;

    for (int i = 0; i < n; i++) {
      if (visited[i])
        continue;

      visited[i] = 1;
      cnt = 0;
      dfs(i, adj, visited);
      ans += cnt * (n - cnt);
    }
    return ans / 2;
  }
};
