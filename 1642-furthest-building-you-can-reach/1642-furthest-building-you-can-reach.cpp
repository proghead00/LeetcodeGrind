class Solution {
public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    int i = 0;
    priority_queue<int> pq;

    for (i; i < heights.size() - 1; i++) {
      if (heights[i] >= heights[i + 1])
        continue;

      int diff = heights[i + 1] - heights[i];

      if (diff <= bricks) {
        bricks -= diff;
        pq.push(diff);
      }
      // no sufficient bricks are left but we got ladders
      else if (ladders) {
        if (pq.size() and pq.top() > diff) {
          bricks += pq.top();
          pq.pop();
          pq.push(diff);
          bricks -= diff; // using bricks to replace ladders
        }
        ladders--; // since we can use one ladder for any height, we are using
                   // the ladder instead of bricks (replacing them)
      } else
        break;
    }
    return i;
  }
};
