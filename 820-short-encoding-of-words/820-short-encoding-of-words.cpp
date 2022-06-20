
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

  int insert(string word) {
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
      return word.size() + 1;
    else
      return 0;
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
      ans += t.insert(w);

    return ans;
  }
};
