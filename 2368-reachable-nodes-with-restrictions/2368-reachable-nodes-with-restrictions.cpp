class Solution {
public:
  vector<int> gr[100005];
  int vis[100005];

  int help(int cur, int par) {
    if (cur == -1) return 0;
    int cnt = 1;

    vis[cur] = 1;
    for (auto &x : gr[cur]) {
      if (x == par or vis[x] == 1) continue;
      cnt += help(x, cur);
    }

    return cnt;
  }

  int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted) {

    for (auto &g : gr) g.clear();

    memset(vis, 0, sizeof(vis));


    // mark the restricted nodes as visited so that we don't need to go thru them
    for (auto pp : restricted) {
      vis[pp] = 1;
    }

    for (auto x : edges) {
      if (vis[x[0]] or vis[x[1]]) continue;

      // create adjacency list
      gr[x[0]].push_back(x[1]);
      gr[x[1]].push_back(x[0]);
    }

    return help(0, -1);
  }
};
