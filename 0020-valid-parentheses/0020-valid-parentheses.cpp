class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char x : s)    {
            if (x == '(' or x == '{' or x == '[') st.push(x);

            else {
                // if the stack is empty you CANNOT push a closing bracket
                // if (s.empty()) return false;

                if (st.empty() or
                        (st.top() == '(' and x != ')')
                        or (st.top() == '{' and x != '}')
                        or (st.top() == '[' and x != ']'))

                    return false;

                // if we get a matching closing bracket, pop it
                st.pop();

            }
        }

        return st.empty();
    }
};