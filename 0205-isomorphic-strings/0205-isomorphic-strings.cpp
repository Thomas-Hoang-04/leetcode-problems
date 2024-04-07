class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int map[2][256] = {0};
        int i = 0;
        for (i; i < s.size(); i++) {
            if (map[0][s[i]] != map[1][t[i]]) return false;
            map[0][s[i]] = i + 1;
            map[1][t[i]] = i + 1;
        }
        return true;
    }
};