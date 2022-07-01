class Solution {
public:

       bool uniformity(vector<vector<int>> &grid, int x) {
              int temp = grid[0][0] % x;
              for (auto pp1 : grid) {
                     for (auto pp2 : pp1) {
                            // cout << "pp2 " << pp2 << endl;
                            if (pp2 % x != temp)
                                   return false;
                     }
              }

              return true;
       }

       int minOperations(vector<vector<int>> & grid, int x) {

              if (!uniformity(grid, x)) return -1;

              vector<int> v;

              for (auto pp1 : grid) {
                     for (auto pp2 : pp1) {
                            v.push_back(pp2);
                     }
              }

              sort(v.begin(), v.end());

              // for (int ok : v) cout << "ok " << ok << endl;

              int m1 = v[v.size()/2];
              int ans = 0 ;
              for(auto xe : v ) ans += abs(xe-m1)/x;
              return ans ;

       }
};