class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        map<int, int>::iterator m = mp.end();
        int t = nums.size();
        int t2, i;
        for (i = 0; i < t; ++i) {
            t2 = target - nums[i];
            if (mp.find(t2) != m) {
                break;
            } else mp[nums[i]] = i;
        }
        return { mp[t2], i };
    }
};