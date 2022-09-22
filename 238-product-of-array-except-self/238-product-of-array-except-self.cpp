class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // pref: 1,   2, 6, 24 (LEFT MULTIPLICATION)
        // post: 24, 24, 12, 4 (RIGHT MULTIPLICATION)
        // ans:  1 * 24, 1 * 12, 2 * 4, 6 * 1
        
        vector<int> pref, post;
        int preVal = 1, postVal = 1;
        // cout << preVal << " " << postVal << endl;
       
        
        for(int x: nums){
            preVal *= x;
            pref.push_back(preVal);
        }
        
        for(int i = nums.size() - 1; i >= 0; i--){
            postVal *= nums[i];
            post.push_back(postVal);
        }
        reverse(post.begin(), post.end());
        
//         for(auto x: pref) cout << x << " ";
//         cout << endl;
//         for(auto x: post) cout << x << " ";
        
        vector<int> ans(nums.size());
        
        ans[0] = post[1];
        ans[nums.size() - 1] = pref[nums.size() - 2];
        
        for(auto x: ans) cout << x << " ";
        
        for(int i = 1; i < nums.size() - 1; i++){
            ans[i] = pref[i-1] * post[i+1];
        }
    
        
        return ans;
    }
};