class Solution {
private:
    int pairs;
    int clear(string& carb, string match, int pts) {
        int total_pts = 0;
        int w_idx = 0;

        for (int r_idx = 0; r_idx < carb.size(); r_idx++) {
            carb[w_idx++] = carb[r_idx];

            if (w_idx < 2) continue;
            if (carb[w_idx - 2] == match[0] && carb[w_idx - 1] == match[1]) {
                w_idx -= 2;
                total_pts += pts;
            } 
        }
        
        carb.erase(carb.begin() + w_idx, carb.end());

        return total_pts;
    }
public:
    int maximumGain(string s, int x, int y) {
        pairs = 0;

        if (x > y) {
            pairs += clear(s, "ab", x);
            pairs += clear(s, "ba", y);
        } else {
            pairs += clear(s, "ba", y);
            pairs += clear(s, "ab", x);
        }

        return pairs;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
