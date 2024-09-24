#pragma GCC optimize(O3, "unroll-loops")

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> pref;
        for (int val: arr1) {
            while (!pref.count(val) && val) {
                pref.insert(val);
                val /= 10;
            }
        }

        int maxPref = 0;

        for (int val: arr2) {
            while (!pref.count(val) && val) val /= 10;
            if (val) maxPref = max(maxPref, static_cast<int>(log10(val) + 1));
        }

        return maxPref;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();