// Time: O(n), Space: O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<char> leftStack;
        for (char& ch: s) {
            switch (ch) {
                case '(':
                case '{':
                case '[':
                    leftStack.push(ch);
                    break;
                case ')':
                    if (leftStack.empty() || leftStack.top() != '(') return false;
                    leftStack.pop(); break;
                case '}':
                    if (leftStack.empty() || leftStack.top() != '{') return false;
                    leftStack.pop(); break;
                case ']':
                    if (leftStack.empty() || leftStack.top() != '[') return false;
                    leftStack.pop(); break;
                default:
                    return false;
            }
        }
        return leftStack.empty();
    }
};