#pragma GCC optimize(O3, "unroll-loops")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")

class Solution {
private: 
    vector<vector<int>> ans;
    vector<int> curr;
    void backtrack(vector<int>& cand, int remain, int idx) {
        if (remain == 0) {
            ans.push_back(curr);
            return;
        }
        for (int i = idx; i < cand.size() && remain >= cand[i]; i++) {
            if (i == idx || cand[i] != cand[i - 1]) {
                curr.push_back(cand[i]);
                backtrack(cand, remain - cand[i], i + 1);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();