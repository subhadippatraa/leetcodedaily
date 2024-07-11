
class Solution {
public:
    string reverseParentheses(string s) {

        stack<char> st1;
        queue<char> st2;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ')') {
                st1.push(s[i]);
            } else {
                while (!st1.empty() && st1.top() != '(') {
                    st2.push(st1.top());
                    st1.pop();
                }
                if (!st1.empty()) {
                    st1.pop(); // pop the '('
                }
                while (!st2.empty()) {
                    st1.push(st2.front());
                    st2.pop();
                }
            }
        }

        std::string res;
        while (!st1.empty()) {
            res += st1.top();
            st1.pop();
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};
