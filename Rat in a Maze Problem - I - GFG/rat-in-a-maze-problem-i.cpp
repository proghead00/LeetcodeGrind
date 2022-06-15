// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans,
               string temp, vector<vector<int>> &vis, int dx[], int dy[]) {
    
    
    	if (i == n - 1 and j == n - 1) {
    		ans.push_back(temp);
    		return;
    	}
    
    	string dir = "DLRU"; //sorted order
    
    	for (int k = 0; k < 4; k++) {
    
    		int xx = i + dx[k];
    		int yy = j + dy[k];
    
    		if (xx>=0 and yy>=0 and xx < n and yy < n and !vis[xx][yy] and m[xx][yy]) {
    			vis[i][j] = 1;
    			solve(xx, yy, m, n, ans, temp + dir[k], vis, dx, dy);
    			vis[i][j] = 0;
    		}
    	}
    }


    vector<string> findPath(vector<vector<int>> &m, int n) {
	// Your code goes here

	vector<string> ans;

	vector<vector<int>> vis(n, vector<int> (n, 0));

	int dx[] = {1, 0, 0, -1};
	int dy[] = {0, -1, 1, 0};

	if (m[0][0]) solve(0, 0, m, n, ans, "", vis, dx, dy);

	return ans;

    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends