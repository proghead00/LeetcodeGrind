class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto x: nums) mp[x]++;
        
        // store frequencies as indices
        vector<vector<int>> freq(nums.size() + 1); // each bucket will have the elements and each bucket's index is it's frequency
        
        for(auto x: mp){
            int idx = x.second;
            freq[idx].push_back(x.first);
        }
        
        int cnt = 0;
        vector<int> ans;
        for(int i = freq.size() - 1; i >= 0; i--){
            for(int j = 0; j < freq[i].size(); j++){
                
                if(cnt == k) return ans;
                ans.push_back(freq[i][j]);
                
                cnt++;
            }          
        }
        
        return ans;
        
    }
};