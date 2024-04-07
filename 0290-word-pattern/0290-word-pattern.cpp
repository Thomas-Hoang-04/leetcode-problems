class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> m1;
        map<string, char> m2;
        int i = 0, j = 0;
        string t = "";
        for (i; i < pattern.length(); i++) {
            if (j >= s.length()) return false;
            while (s[j] != ' ' && j < s.length()) {
                t += s[j++];
            };
            if (m1.find(pattern[i]) != m1.end()) {
                if (m1[pattern[i]] != t) return false;
            } else if (m2.find(t) != m2.end()) {
                if (m2[t] != pattern[i]) return false;
            }
            else {
                m1[pattern[i]] = t;
                m2[t] = pattern[i];
            }
            j++;
            t = "";
        }
        if (j < s.length()) return false;
        return true;
    }
};