class Solution {
public:
  long long countBadPairs(vector<int>& nums) {

    /*
       j - i != nums[j] - nums[i]
    => j - nums[j] != i - nums[i]

    [..., 4] -> Since I got != as the condition, so I need to find if there are other numbers that are not equal to the current number.
          |
          i           i means that we have explored i numbers before (since i starts from 0)


    */

    unordered_map<int, int> mp;

    long long ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      ans += i - mp[i - nums[i]]; // taking upto i, so I need to substract the number of times we have seen the number before
      mp[i - nums[i]]++;
    }

    return ans;
  }
};
