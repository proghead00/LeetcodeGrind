class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        // [1,0, 2] => global = 1, local = 1 (hence, return true)
        // [2, 0, 1] => global = {2,0} {2,1}; local = {2,0}
        //                  \U0001f449 i points at 0 (2), and i+2 is (1), and we find that 2 (i) > 1 (i+2) which violates local inversion property

        int n = nums.size();
        int mx = 0;
        for (int i = 0; i < n - 2; i++) {
            mx = max(mx, nums[i]); // mx is the max number found so far, so if we get an element at i+2 which is less than mx, it forms global inv

            if (mx > nums[i + 2])
                return false;
        }

        return true;
    }
};