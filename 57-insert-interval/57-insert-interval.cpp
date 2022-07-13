// 3 types of insertions:

// 1.  Push the ``intervals``` that come before ```newInterval``` when there is NO overlap

// 2. There is overlap, so we gotta extend our range of ```mergeOverlaps``` as [minimum....maximum] values respectively

// 3. After the merging is completed, there is no overlap henceforth. We can
// just push the remaining last elements into ```ans```


class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {

    int i = 0;
    vector<vector<int>> ans;

    int n = intervals.size();
    // intervals input is already sorted

    // 1.
    while (i < n) {
      if (intervals[i][1] >= newInterval[0])
        break;
      ans.push_back(intervals[i]);
      i++;
    }

    // 2.
    vector<int> mergeOverlaps = newInterval;
    while (i < n) {

      // if there's no overlap
      if (intervals[i][0] > newInterval[1])
        break;

      // we need to expand the mergeOverlaps according to min and max
      mergeOverlaps[0] = min(mergeOverlaps[0], intervals[i][0]);
      mergeOverlaps[1] = max(mergeOverlaps[1], intervals[i][1]);
      i++;
    }

    ans.push_back(mergeOverlaps);

    // 3.
    while (i < n) {
      ans.push_back(intervals[i]);
      i++;
    }
    return ans;
  }
};
