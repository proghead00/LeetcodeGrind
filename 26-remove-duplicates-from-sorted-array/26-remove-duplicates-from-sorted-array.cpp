class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        /* upper_bound :
         returns an iterator pointing to the element JUST greater than value given if present
         if not present, it returns points to end(), and when we subtract the value with .begin(), we get the "index" as the size of the array
        */

        int idx = 0;
        while (true) {
            int upper = upper_bound(nums.begin(), nums.end(), nums[idx]) - nums.begin();

            if (upper == nums.size()) return ++idx;

            nums[++idx] = nums[upper];
        }

    }
};