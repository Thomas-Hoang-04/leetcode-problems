class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int, greater<int>> track;
        int maxSub = 0, l = 0;
        for (int r = 0; r < nums.size(); r++) {
            track.insert(nums[r]);
            while (abs(*track.begin() - *track.rbegin()) > limit) {
                track.erase(track.find(nums[l]));
                l++;
            }
            maxSub = max(maxSub, r - l + 1);
        }
        return maxSub;
    }
};