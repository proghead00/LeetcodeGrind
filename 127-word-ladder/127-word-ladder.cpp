class Solution {
public:
  int ladderLength(string &beginWord, string &endWord, vector<string> &wordList) {
    unordered_set<string> setList(wordList.begin(), wordList.end());

    if (!setList.count(endWord)) return 0;  // if destination endWord is not present in our list, return 0

    int levelAns = 0;        // to count the number of nodes/steps needed to reach the destination word

    queue<string> q;
    q.push(beginWord);    // push the starting node into queue, as we did in BFS [beginWord is our root]

    while (!q.empty()) {

      int sz = q.size();
      levelAns++;

      while (sz--) {
        auto curWord = q.front();
        q.pop();

        // find the next word which can be formed after curWord by trying out wildcard matchings (a-z)
        for (int i = 0; i < curWord.size(); ++i) {
          string temp = curWord;

          // try to change each character, make a new word find in set
          for (char ch = 'a'; ch <= 'z'; ch++) {

            temp[i] = ch;      // new word, since we are replacing with a new character

            // if new word is same as curr word simply ignore
            if (temp == curWord) continue;
            if (temp == endWord) return levelAns + 1; // found the endWord => return levelAns

            // if we find the newWord is present in our map, put in the queue
            // as the next destination node, which will help is to reach our endWord

            if (setList.count(temp)) {
              q.push(temp);    // push the newWord or a node into queue
              setList.erase(temp);   // remove that word since we cannot have duplicates
            }
          }
        }
      }
    }
    return 0;
  }
};