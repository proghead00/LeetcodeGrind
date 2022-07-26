class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;

        map<vector<int>, int> mp;

        for (int i = 0; i < grid.size(); i++)
            mp[grid[i]]++;

        for (int i = 0; i < grid[0].size(); i++) {
            vector<int> v;

            for (int j = 0; j < grid.size(); j++)
                v.push_back(grid[j][i]);

            ans += mp[v];
        }

        return ans;
    }
};