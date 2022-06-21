class Solution {
public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders) {

    // max heap
    priority_queue<int> pq;


    for (int i = 0; i < heights.size() - 1; i++) {
      int diff = heights[i + 1] - heights[i];
      if (diff <= 0)
        continue;

      // utilise all the bricks first (until we can)

      if (diff <= bricks) {
        bricks -= diff;
        pq.push(diff);
      }


      // if we cannot use bricks for this position, so we try to use ladders (no boundary of length ==> here, it's always guranteed to have 'diff' length)

      else if (ladders) {

        // check if we can replace bricks (used before) with ladders

        if (pq.size() and pq.top() > diff) {
          // cuz if pq.top() < diff, there's no point in using them either cuz we cannot fill up

          bricks += pq.top(); // we recover the bricks used previously
          pq.pop();
          pq.push(diff);
          bricks -= diff; // use bricks here

          ladders--; // put ladder in the previous position
        }

        // when we MUST use ladders cuz we don't have enough bricks
        else
          ladders--;
      }

      else {
        // neither bricks nor ladders are available
        return i;
      }
    }
    return heights.size() - 1;
  }
};
