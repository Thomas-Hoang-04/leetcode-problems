#pragma GCC optimize (O3, "unroll-loops")

class Solution {
private:
    string findRoot(string word) {
        string sub;
        for (int i = 0; i < word.size(); i++) {
            sub = word.substr(0, i + 1);
            if (dict.find(sub) != dict.end()) return sub;
        }
        return word;
    }
    unordered_set<string> dict;
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        istringstream stream(sentence);
        dict = unordered_set<string>(dictionary.begin(), dictionary.end());

        string word, ans = "";
        while (getline(stream, word, ' ')) ans += findRoot(word) + " ";
        ans.pop_back();
        return ans;
    }
};