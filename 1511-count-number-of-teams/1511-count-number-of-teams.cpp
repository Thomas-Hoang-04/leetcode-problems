#pragma GCC optimize(O3, "unroll-loops")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int cnt = 0;
        for (int i = 0; i < rating.size(); i++) 
            for (int j = i + 1; j < rating.size(); j++) 
                for (int k = j + 1; k < rating.size(); k++)
                    if ((rating[i] < rating[j] && rating[j] < rating[k]) || (rating[i] > rating[j] && rating[j] > rating[k])) cnt++;
        return cnt;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();