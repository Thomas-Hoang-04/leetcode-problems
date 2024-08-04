class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> storeSub;
        int sum;
        for (int i = 0; i < nums.size(); i++) {
            sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                storeSub.push_back(sum);
            }
        }
        sort(storeSub.begin(), storeSub.end());
        const int mod = 1e9 + 7;
        sum = 0;
        left--;
        while (left < right) sum = (sum + storeSub[left++]) % mod;
        return sum;
    }
};