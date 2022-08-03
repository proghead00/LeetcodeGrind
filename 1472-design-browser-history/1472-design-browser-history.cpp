class BrowserHistory {
private:
  stack<string> back_stack;
  stack<string> forward_stack;

public:
  BrowserHistory(string homepage) { back_stack.push(homepage); }

  void visit(string url) {
    back_stack.push(url);

    // For case:

    // browserHistory.visit("linkedin.com");
    // browserHistory.forward(2);
    // You are in "linkedin.com", you cannot move forward any steps.

    // So in this case, I have youtube.com in my forward_stack but I need to
    // clear the forward_stack, else I will get youtube.com which is WRONG
    // because I have LinkedIn as the most recent visited website.

    while (!forward_stack.empty()) {
      forward_stack.pop();
    }
  }

  string back(int steps) {
    int x = back_stack.size();
    if (x >= steps)
      x = steps;

    while (x--) {
      if (back_stack.size() > 1) {
        forward_stack.push(back_stack.top());
        back_stack.pop();
      }
    }
    return back_stack.top();
  }

  string forward(int steps) {
    int x = forward_stack.size();
    if (x >= steps)
      x = steps;

    while (x-- and forward_stack.size()) {
      back_stack.push(forward_stack.top());
      forward_stack.pop();
    }
    return back_stack.top();
  }
};
