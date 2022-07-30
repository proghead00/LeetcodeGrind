class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> ans;
        
        // non overlaps
        int i = 0;
        while(i < intervals.size() and intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        
        // i will point to the next vector 
        // overlap case
        
        vector<int> temp = newInterval;
        
        while(i < intervals.size() and newInterval[1] >= intervals[i][0] and intervals[i][1] >= newInterval[0]){
            temp[0] = min(temp[0], intervals[i][0]);
            temp[1] = max(temp[1], intervals[i][1]);
            i++;
        }
        
        ans.push_back(temp);
        
        while(i < intervals.size()){
            ans.push_back(intervals[i]); 
            i++; 
        }
        
        return ans;
    }
};