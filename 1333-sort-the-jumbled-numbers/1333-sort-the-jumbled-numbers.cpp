class Solution {
private:
    int create_map(int org, vector<int>& mp) {
        if (org == 0) return mp[0];
        string ans = "";
        while (org) {
            ans = to_string(mp[org % 10]) + ans;
            org /= 10;
        }
        return stoi(ans);
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