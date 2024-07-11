class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> match_par;
        vector<int> match(s.size());
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '(') match_par.push(i);
            else if (s[i] == ')') {
                match[i] = match_par.top();
                match[match_par.top()] = i;
                match_par.pop();
            }
        }
        string res;
        for (int i = 0, dir = 1; i < s.size(); i += dir) {
            if (s[i] == '(' || s[i] == ')') {
                i = match[i];
                dir = -dir;
            } else res += s[i];
        }
        return res;
    }
};