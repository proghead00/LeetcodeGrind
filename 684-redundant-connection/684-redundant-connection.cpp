class Solution {
public:
    int find(int node, vector<int>& par) {
        if (node == par[node]) return node;
        else return par[node] = find(par[node], par);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& es) {
        vector<int> par(es.size() + 1);

        // initially every node is the parent of itself
        for (int i = 1; i < es.size() + 1; i++)
            par[i] = i;

        for (auto &e : es) {
            int ff = find(e[0], par);
            int ss = find(e[1], par);

            if (ff != ss) par[ff] = ss;
            else return {e[0], e[1]};
        }
        return {};
    }
};