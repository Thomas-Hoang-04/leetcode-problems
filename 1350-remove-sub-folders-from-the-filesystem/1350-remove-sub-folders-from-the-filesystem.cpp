class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> result;
        result.push_back(folder[0]);

        for (int i = 1; i < folder.size(); i++) {
            string prev = result.back();
            prev += '/';

            if (folder[i].compare(0, prev.size(), prev)) result.push_back(folder[i]);
        }

        return result;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();