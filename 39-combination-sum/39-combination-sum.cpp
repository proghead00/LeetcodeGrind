class Solution {
public:
    
    void sum(vector<int>& candidates, int target, int idx, vector<vector<int>> &ans, vector<int> &ds){
    
        if(target==0){
            ans.push_back(ds);
            return;
        }
        
        if(idx == candidates.size()) return;
        
        if(target<0) return;
        
        
        sum(candidates, target, idx+1, ans, ds);
            
        ds.push_back(candidates[idx]);
        sum(candidates, target-candidates[idx], idx, ans, ds);
        ds.pop_back();
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sum(candidates, target, 0, ans, ds);
        
        return ans;
    }
};