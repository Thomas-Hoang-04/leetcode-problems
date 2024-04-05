class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i = 0;
        for (i; i < s.length(); i++) {
            if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (st.empty()) return false;
                if (abs(s[i] - st.top()) > 2) return false;
                else st.pop();
            } else st.push(s[i]);
        }
        return st.empty();
    }
};