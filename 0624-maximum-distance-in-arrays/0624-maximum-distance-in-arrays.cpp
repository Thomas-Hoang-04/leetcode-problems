class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int eMin = 1e5, eMax = -1e5;
        int diff = 0;
        for (vector<int>& arr: arrays) {
            diff = max({diff, eMax - arr[0], arr.back() - eMin});
            eMin = min(eMin, arr[0]);
            eMax = max(eMax, arr.back());
        }
        return diff;
    }
};