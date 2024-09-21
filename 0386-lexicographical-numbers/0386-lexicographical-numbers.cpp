class Solution {
private:
    vector<int> ans;
    void genNums(int curr, int lim) {
        if (curr > lim) return;

        ans.push_back(curr);

        for (int next = 0; next <= 9; ++next) {
            int nextNum = curr * 10 + next;
            if (nextNum <= lim) genNums(nextNum, lim);
            else break;            
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        for (int st = 1; st <= 9; ++st) genNums(st, n);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();