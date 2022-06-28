class Solution {
public:
  int minDeletions(string s) {
    map<char, int> freq;
    for (char x : s)
      freq[x]++;

    // using while loop because:
    // aabbbccc ==> freq: {a: 2, b: 3, c: 3} ==> x.second
    // 2 3 3 ==> but, we arleady have faced 3 efore
    //          ==> 2 3 2 ==> but, we already have faced 2 before
    //                 ==> 2 3 1

    map<char, int> vis; //   sorted
    int del = 0;
    for (auto x : freq) {
      while (x.second and vis.find(x.second) != vis.end()) {
        del++;
        x.second--;
      }
      if (!vis[x.second])
        vis[x.second]++;
    }
    return del;
  }
};
