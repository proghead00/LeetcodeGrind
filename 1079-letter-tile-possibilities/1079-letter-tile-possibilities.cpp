class Solution {
public:
  int cnt = 0;
  void help(string tiles, vector<int> &vis) {
    for (int i = 0; i < tiles.size(); i++) {
      if (vis[i] or (i and tiles[i] == tiles[i - 1] and !vis[i-1])) continue;
      vis[i] = 1;
      cnt++;
      help(tiles, vis);
      vis[i] = 0;
    }
  }

  int numTilePossibilities(string tiles) {
    sort(tiles.begin(), tiles.end());
    vector<int> vis(tiles.size(), 0);
    help(tiles, vis);
    return cnt;
  }
};
