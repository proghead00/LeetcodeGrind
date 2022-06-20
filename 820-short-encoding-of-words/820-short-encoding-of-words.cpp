
class Node {
public:
  char data;
  unordered_map<char, Node *> mp;
  bool isTerminal;

  Node(char d) {
    data = d;
    isTerminal = false;
  }
};

class Trie {
public:
  Node *root;
  Trie() { root = new Node('\0'); }

  void insert(string word, int &ans) {
    Node *temp = root;
    reverse(word.begin(), word.end());

    int f = 0;
    for (char w : word) {
      if (!temp->mp.count(w)) {
        Node *n = new Node(w);
        temp->mp[w] = n;
        f = 1;
      }
      temp = temp->mp[w];
    }
    temp->isTerminal = true;
    if (f)
      ans += word.size() + 1;
  }
};

class Solution {
public:
  int minimumLengthEncoding(vector<string> &words) {

    Trie t;

    int ans = 0;
    sort(words.begin(), words.end(),
         [](string a, string b) { return a.size() > b.size(); });

    for (string w : words)
      t.insert(w, ans);

    return ans;
  }
};
