class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> mp;
        for (int i = 0; i < heights.size(); i++) mp[heights[i]] = names[i];
        sort(heights.begin(), heights.end(), greater<int>());
        for (int i = 0; i < heights.size(); i++) names[i] = mp[heights[i]];
        return names;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

