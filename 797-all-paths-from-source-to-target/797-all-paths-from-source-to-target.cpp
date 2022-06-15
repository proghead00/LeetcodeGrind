class Solution {
public:
  void dfs(int cur, int par, vector<vector<int>> &graph, vector<int> &path,
           vector<vector<int>> &ans) {
    // if (!graph[cur].size())
    path.push_back(cur);

    if (cur == graph.size() - 1) {
      ans.push_back(path);
      //   return;
    }

    for (int i = 0; i < graph[cur].size(); i++) {
      if (graph[cur][i] == par)
        continue;
      dfs(graph[cur][i], cur, graph, path, ans);
    }
    path.pop_back();
  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<vector<int>> ans;
    vector<int> path;
    dfs(0, -1, graph, path, ans);
    return ans;
  }
};
