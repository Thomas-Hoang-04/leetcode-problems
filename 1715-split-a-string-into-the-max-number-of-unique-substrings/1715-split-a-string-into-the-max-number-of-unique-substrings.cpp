class Solution {
private:
    unordered_set<string> track;
    int maxSub = 0;
    void backtrack(const string& s, int idx, int curr) {
        if (curr + s.size() - idx <= maxSub) return;

        if (idx == s.size()) {
            maxSub = max(curr, maxSub);
            return;
        }

        for (int e = idx + 1; e <= s.size(); e++) {
            string sub = s.substr(idx, e - idx);
            if (track.find(sub) == track.end()) {
                track.insert(sub);
                backtrack(s, e, curr + 1);
                track.erase(sub);
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        backtrack(s, 0, 0);
        return maxSub;
    }
};