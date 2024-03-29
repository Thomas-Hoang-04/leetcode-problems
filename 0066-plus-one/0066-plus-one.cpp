class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        int c = (digits[i] + 1) / 10;
        digits[i] = (digits[i] + 1) % 10;
        while (c && i > 0) {
            --i;
            c = (digits[i] + 1) / 10;
            digits[i] = (digits[i] + 1) % 10;
        } 
        if (c) digits.insert(digits.begin(), 1);
        return digits;
    }
};