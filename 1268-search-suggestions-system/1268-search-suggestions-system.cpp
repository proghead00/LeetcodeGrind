class Node {
public:
  char d;
  map<char, Node *> mp;
  bool isTerminal;

  Node(char d) {
    this->d = d;
    isTerminal = false;
  }
};

class Trie {
public:
  Node *root;
  Trie() { root = new Node('\0'); }

  void insert(string word) {
    Node *temp = root;
    for (char &w : word) {
      if (!temp->mp.count(w)) {
        Node *n = new Node(w);
        temp->mp[w] = n;
      }
      temp = temp->mp[w];
    }
    // after all the characters are inserted, mark the last character as
    // terminal
    temp->isTerminal = true;
  }

  vector<string> search(string &pref) {
    Node *temp = root;
    vector<string> rr;
    for (char &c : pref) {
      if (!(temp->mp.count(c)))
        return {};
      temp = temp->mp[c];
    }

    dfs(pref, rr, temp);
    return rr;
  }

  void dfs(string &pref, vector<string> &rr, Node *temp) {
    // Node *temp = root;
    if (rr.size() == 3)
      return;
    if (temp->isTerminal)
      rr.push_back(pref);

    for (auto &p : temp->mp) {
      string newPref = pref + p.first;
      dfs(newPref, rr, p.second);
    }
  }
};

class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string> &products,
                                           string searchWord) {

    Trie t;
    vector<vector<string>> res;
    vector<string> vv;
    for (string &p : products)
      t.insert(p);

    string pref;
    for (char &c : searchWord) {
      pref += c;
      res.push_back(t.search(pref));
    }

    return res;
  }
};
