class Solution {
public:

  vector<int> colorVisited;

  // COLOR:
  // 0 -> not visited; 1-> visisted and colored 1; 2-> visited and colored 2

  bool oddCycle(vector<vector<int>>& graph, int cur, int par, int col) {

    colorVisited[cur] = col;

    for (auto nbr : graph[cur]) {
      if (!colorVisited[nbr]) {
        if (oddCycle(graph, nbr, cur, 3 - col))
          return true;
      }

      else if (nbr != par and col == colorVisited[nbr])
        return true;
    }

    return false;

  }

  bool isBipartite(vector<vector<int>>& graph) {
    // if odd length cycle is there, it's NOT a bipartite

    colorVisited.resize(graph.size() + 1);

    for (int i = 0; i < graph.size(); i++) {
      if (!colorVisited[i])
        if (oddCycle(graph, i, -1, 1))
          return false;
    }

    return true;
  }
};


