class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    
        sort(intervals.begin(), intervals.end(), [] (vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        
        int check = intervals[0][1]; // the first one is fixed, cuz it will always come first nonetheless without overlapping
        
        int ans = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(check > intervals[i][0]) ans++;
            else check = intervals[i][1];
        }
        
        return ans;
        
    }
};