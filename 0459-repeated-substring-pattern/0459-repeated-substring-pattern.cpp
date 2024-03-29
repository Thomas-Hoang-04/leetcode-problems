class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string sf = s + s;
        return sf.substr(1, sf.length() - 2).find(s) != string::npos;
    }
};