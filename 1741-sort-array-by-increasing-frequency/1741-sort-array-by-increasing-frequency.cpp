class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int freq[201] = {0};
        for (int n: nums) freq[n + 100]++;
        sort(nums.begin(), nums.end(), [&](int a, int b){
            if (freq[a + 100] == freq[b + 100]) return a > b;
            return freq[a + 100] < freq[b + 100];
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