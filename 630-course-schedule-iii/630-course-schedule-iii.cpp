class Solution {
public:
  int scheduleCourse(vector<vector<int>>& courses) {
    priority_queue<int> pq;

    sort(courses.begin(), courses.end(), [](auto a, auto b) {
      return (a[1] != b[1]) ? a[1] < b[1]: a[0] > b[0];
    });

    int tt = 0;
    for (auto c : courses) {
      if (c[0] <= c[1] and c[0] + tt <= c[1]) {
        pq.push(c[0]); // c[1] doesn't matter since it will change
        tt += c[0];
      }
      else {
        if (pq.size() and pq.top() > c[0]) {

          // can swap
          tt -= pq.top();
          pq.pop();
          pq.push(c[0]);
          tt += c[0];
        }
      }
    }

    return pq.size();
  }
};