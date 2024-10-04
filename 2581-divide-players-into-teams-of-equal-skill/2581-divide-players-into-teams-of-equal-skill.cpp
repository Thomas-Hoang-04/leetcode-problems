#pragma GCC optimize(O3, "unroll-loops")

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        const int skillSize = skill.size();
        long sum = 0;
        for (int i = 0; i < skillSize; i++)
            sum += skill[i];
        if (sum % (skillSize / 2))
            return -1;
        const int tar = sum / (skillSize / 2);
        sum = 0;
        array<int, 1001> mp;
        mp.fill(0);
        int t, size = 0;
        for (int i = 0; i < skillSize; i++) {
            t = tar - skill[i];
            if (mp[t]) {
                sum += skill[i] * t;
                mp[t]--;
                size--;
            } else {
                mp[skill[i]]++;
                size++;
            }
        }
        return size ? -1 : sum;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();