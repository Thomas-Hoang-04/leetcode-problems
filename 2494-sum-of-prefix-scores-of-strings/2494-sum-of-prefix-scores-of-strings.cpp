#pragma GCC optimize(O3, "unroll-loops")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")

struct TrieNode {
    TrieNode* next[26] = {};
    int cnt = 0;
};

class Solution {
private:
    TrieNode root;

    void insert(string w) {
        TrieNode* node = &root;
        for (char c: w) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node->next[c - 'a']->cnt++;
            node = node->next[c - 'a'];
        }
    }

    int count(string w) {
        TrieNode* node = &root;
        int ans = 0;
        for (char c: w) {
            ans +=  node->next[c - 'a']->cnt;
            node = node->next[c - 'a'];
        }
        return ans;
    }
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) insert(words[i]);
        vector<int> scores(words.size(), 0);
        for (int i = 0; i < words.size(); i++) scores[i] = count(words[i]);
        return scores;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();