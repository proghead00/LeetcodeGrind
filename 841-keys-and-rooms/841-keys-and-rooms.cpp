class Solution {
public:

    void dfs(vector<vector<int>> &gr, vector<bool> &visited, int cur) {
        visited[cur] = 1;

        for (auto nbr : gr[cur]) {
            if (!visited[nbr])
                dfs(gr, visited, nbr);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        vector<bool> visited(rooms.size() , 0);
        dfs(rooms, visited, 0);

        for (int i = 0; i < rooms.size(); i++) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;

    }
};