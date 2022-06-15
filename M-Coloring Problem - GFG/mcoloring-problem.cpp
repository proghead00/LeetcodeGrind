// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.


bool ok(int node, int col[], bool graph[101][101], int N, int i){
    
    // go to the adjacent nodes and check
    for(int k=0; k<N; k++){
        if(k!=node and graph[k][node]==1 and col[k]==i){
            return false;
        }
    }
    
    return true;
}

bool check(int node, int col[], int m, int N, bool graph[101][101]){
    
    // i could colour all the nodes (ekse we'd have returned false from the calls)
    if(node == N){
        return true;
    }
    
    // try colours from 1 to n 
    for(int i=1; i<=m; i++){
        // ok will check if it's possible to colour that node with that colour (no adjacent nodes will have same colours)
        
        if(ok(node, col, graph, N, i)){
            col[node] = i; // assign the color to the node
            if(check(node+1, col, m, N, graph)) return true;
            
            // backtrack when false; change it to 0 and we'll try for other colours
            col[node] = 0;
        }
    }
    
    // false, when there's no colour left to try out
    return false;
        
}
bool graphColoring(bool graph[101][101], int m, int N) {
    // your code here
    int col[N] = {0};
    if(check(0, col, m, N, graph)) return true;
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends