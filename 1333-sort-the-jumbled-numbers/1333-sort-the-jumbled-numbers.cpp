#pragma GCC optimize(O3, "unroll-loops")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")

typedef pair<int, int> p2;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<p2> mp_pair;
        int map_val, pl, org;
        for (int i = 0; i < nums.size(); i++) {
            if (!nums[i]) {
                mp_pair.push_back({mapping[0], i});
                continue;
            }
            org = nums[i];
            map_val = 0;
            pl = 1;
            while (org) {
                map_val = pl * mapping[org % 10] + map_val;
                pl *= 10;
                org /= 10;
            }
            mp_pair.push_back({map_val, i});
        }
        sort(mp_pair.begin(), mp_pair.end());
        mapping.clear();
        for (p2& p: mp_pair) mapping.push_back(nums[p.second]);
        return mapping;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();