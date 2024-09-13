#pragma GCC optimize(O3, "unroll-loops")

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for (int i = 1; i < arr.size(); i++) arr[i] ^= arr[i - 1];
        for (vector<int>& q: queries) 
            ans.push_back(q[0] == 0 ? arr[q[1]] : arr[q[0] - 1] ^ arr[q[1]]);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();