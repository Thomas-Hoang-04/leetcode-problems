/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TrieNode {
    struct TrieNode* next[26];
    int cnt;
};

struct TrieNode* createTrieNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    if (node) {
        node->cnt = 0;
        for (int i = 0; i < 26; i++) {
            node->next[i] = NULL;
        }
    }
    return node;
}

void insert(struct TrieNode* root, char* w) {
    struct TrieNode* node = root;
    for (int i = 0; i < strlen(w); i++) {
        if (!node->next[w[i] - 'a']) 
            node->next[w[i] - 'a'] = createTrieNode();
        node->next[w[i] - 'a']->cnt++;
        node = node->next[w[i] - 'a'];
    }
}

int count(struct TrieNode* root, char* w) {
    struct TrieNode* node = root;
    int ans = 0;
    for (int i = 0; i < strlen(w); i++) {
        if (!node->next[w[i] - 'a']) return ans;
        ans += node->next[w[i] - 'a']->cnt;
        node = node->next[w[i] - 'a'];
    }
    return ans;
}

int* sumPrefixScores(char** words, int wordsSize, int* returnSize) {
    struct TrieNode* root = createTrieNode();
    for (int i = 0; i < wordsSize; i++) insert(root, words[i]);
    int* scores = (int*)malloc(wordsSize * sizeof(int));
    *returnSize = wordsSize;
    for (int i = 0; i < wordsSize; i++) scores[i] = count(root, words[i]);
    return scores;
}