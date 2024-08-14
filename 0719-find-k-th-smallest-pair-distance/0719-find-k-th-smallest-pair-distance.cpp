#pragma GCC optimize(O3, "unroll-loops")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")

class Solution {
private:
    int cntPairWithinDist(vector<int>& nums, int maxDist) {
        int cnt = 0;
        int st = 0;

        for (int e = 0; e < nums.size(); e++) {
            while (nums[e] - nums[st] > maxDist) st++;
            cnt += e - st;
        }

        return cnt;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int l = 0, h = nums.back() - nums[0];
        int mid, cnt;

        while (l < h) {
            mid = l + (h - l) / 2;

            cnt = cntPairWithinDist(nums, mid);

            if (cnt < k) l = mid + 1;
            else h = mid;
        }

        return l;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();