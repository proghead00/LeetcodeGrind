
class Node {
public:
  char data;
  unordered_map<char, Node *> mp;

  Node(char d) { data = d; }
};

class Trie {
public:
  Node *root;
  Trie() { root = new Node('\0'); }

  void insert(string word, int &ans) {
    Node *temp = root;
    reverse(word.begin(), word.end());

    // taking a flag so that i can keep track of whether the word is inserted or
    // ignored
    // if f=1 in the end, add the length of the word to ans

    int f = 0;
    for (char w : word) {
      if (!temp->mp.count(w)) {
        Node *n = new Node(w);
        temp->mp[w] = n;
        f = 1;
      }
      temp = temp->mp[w];
    }

    if (f)
      ans += word.size() + 1;
  }
};

class Solution {
public:
  static bool cmp(string a, string b) { return a.size() > b.size(); }

  int minimumLengthEncoding(vector<string> &words) {

    Trie t;
    int ans = 0;

    // "me", time" ==> if i don't sort it, i'll have both "me" and "time"
    // inserted and eventually would get wrong ans
    sort(words.begin(), words.end(), cmp);
    // sort(words.begin(), words.end(),
    //      [](string a, string b) { return a.size() > b.size(); });

    for (string w : words)
      t.insert(w, ans);

    return ans;
  }
};
