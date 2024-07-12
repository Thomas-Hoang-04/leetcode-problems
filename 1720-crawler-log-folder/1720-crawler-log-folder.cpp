class Solution {
private:
    int ops;
    int pos(string log) {
        return log[1] == '.' ? ops > 0 ? -1 : 0 : log[0] == '.' ? 0 : 1;
    }
public:
    int minOperations(vector<string>& logs) {
        ops = 0;
        for(string log: logs) ops += pos(log);
        return ops;
    }
};