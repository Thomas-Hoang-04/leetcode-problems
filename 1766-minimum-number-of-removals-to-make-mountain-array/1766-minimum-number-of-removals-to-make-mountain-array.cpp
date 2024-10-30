class Solution {
private:
    vector<int> getLongestIncSub(vector<int>& v) {
        vector<int> listLen(v.size(), 1);
        vector<int> list = { v[0] };

        for (int i = 1; i < v.size(); i++) {
            int idx = lower_bound(list.begin(), list.end(), v[i]) - list.begin();

            if (idx == list.size()) list.push_back(v[i]);
            else list[idx] = v[i];

            listLen[i] = list.size();
        }

        return listLen;
    }
public:
    int minimumMountainRemovals(vector<int>& nums) {
        const int size = nums.size();
        vector<int> lisLen = getLongestIncSub(nums);
        reverse(nums.begin(), nums.end());
        vector<int> ldsLen = getLongestIncSub(nums);
        reverse(ldsLen.begin(), ldsLen.end());

        int minRemove = INT_MAX;
        for (int i = 0; i < size; i++) 
            if (lisLen[i] > 1 && ldsLen[i] > 1) minRemove = min(minRemove, size - lisLen[i] - ldsLen[i] + 1);

        return minRemove;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();