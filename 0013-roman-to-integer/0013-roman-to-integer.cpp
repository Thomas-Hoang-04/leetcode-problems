class Solution {
public:
    map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int romanToInt(string s) {
        int num = 0, i = s.length() - 1;
        for (i; i >= 0; --i) {
            if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) num -= 1;
            else if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) num -= 10;
            else if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')) num -= 100;
            else num += roman.at(s[i]);
        }
        return num;
    }
};