class Solution {
private:
    int create_map(int org, vector<int>& mp) {
        if (org == 0) return mp[0];
        int pl = 1, ans = 0;
        while (org) {
            ans = pl * mp[org % 10] + ans;
            pl *= 10;
            org /= 10;
        }
        return ans;
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int n: nums) mp[n] = create_map(n, mapping);
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return mp[a] < mp[b];
        });
        return nums;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();