class Solution {
public:
  int maxArea(int h, int w, vector<int> &horizontalCuts,
              vector<int> &verticalCuts) {

    // max gap in horizontal and vertical
    // max diff b/w horizontal cuts and vertical cuts
    // then, max ht diff * wt diff = area (ans)

    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());

    long long int horiMx = 0, vertMx = 0, prev = 0;

    for (auto x : horizontalCuts) {
      horiMx = max(horiMx, x - prev);
      prev = x;
    }
    horiMx = max(horiMx, h - prev); // to check if last cut is at the end

    prev = 0;
    for (auto x : verticalCuts) {
      vertMx = max(vertMx, x - prev);
      prev = x;
    }
    vertMx = max(vertMx, w - prev);
    int mod = 1e9 + 7;
    return horiMx * vertMx % mod;
  }
};
