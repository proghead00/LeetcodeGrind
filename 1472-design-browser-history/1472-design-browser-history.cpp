class BrowserHistory {
private:
  stack<string> back_stack;
  stack<string> forward_stack;

public:
  BrowserHistory(string homepage) { back_stack.push(homepage); }

  void visit(string url) {
    back_stack.push(url);
    forward_stack = stack<string>();
  }

  string back(int steps) {
    while (steps-- and back_stack.size() >= 2) {
      forward_stack.push(back_stack.top());
      back_stack.pop();
    }
    return back_stack.top();
  }

  string forward(int steps) {
    while (steps-- and forward_stack.size()) {
      back_stack.push(forward_stack.top());
      forward_stack.pop();
    }
    return back_stack.top();
  }
};
