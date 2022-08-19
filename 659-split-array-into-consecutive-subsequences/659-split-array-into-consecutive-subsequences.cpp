class Solution {
public:
  bool isPossible(vector<int> &nums) {

    unordered_map<int, int> mp;
    unordered_map<int, int> future;

    for (int x : nums) mp[x]++;

    for (int i = 0; i < nums.size(); i++) {

      if (mp[nums[i]] <= 0) continue;

      if (future[nums[i]]) {
        // we might put this number present in a previous sequence that we have already found
        // why? since MINIMUM length of the sequence is 3
        mp[nums[i]]--;
        future[nums[i]]--;

        // and we can further have the +1 from this number in the future as well (if present in the array obviously)
        future[nums[i] + 1]++;
      }

      else if (future[nums[i]] == 0) {
        // we ought to create a new sequence starting from this
        if (mp[nums[i] + 1] and mp[nums[i] + 2]) {
          mp[nums[i]]--;
          mp[nums[i] + 1]--;
          mp[nums[i] + 2]--;

          future[nums[i] + 3]++; // we can have the +1 element in this sequence (in the future)
        }
        else return false;
      }
    }

    return true;
  }
};
