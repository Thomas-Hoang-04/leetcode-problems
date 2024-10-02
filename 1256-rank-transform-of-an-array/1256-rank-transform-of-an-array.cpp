#pragma GCC optimize(O3, "unroll-loops")

typedef pair<const int, vector<int>> p2;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int>> idxRank;

        int size = arr.size();
        for (int i = 0; i < size; i++) idxRank[arr[i]].push_back(i);

        size = 1;
        for (p2& p: idxRank) {
            for (int idx: p.second) arr[idx] = size;
            size++;
        }
        return arr;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();