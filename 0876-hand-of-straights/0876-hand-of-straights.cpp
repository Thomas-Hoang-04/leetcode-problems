class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return 0;
        map<int, int> mp;
        for (auto t: nums) {
            mp[t]++;
        }
        while (!mp.empty()) {
            int n = mp.begin()->first;
            for (int i = 0; i < k; i++) {
                if (mp[n + i] > 0) {
                    mp[n + i]--;
                    if (mp[n + i] == 0) mp.erase(n + i);
                }
                else return 0;
            }
        }
        return 1;
    }
};