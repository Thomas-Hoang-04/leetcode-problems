class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0, i = 0;
        for (i; i < tickets.size(); ++i) {
            if (tickets[i] < tickets[k]) time += tickets[i];
            else {
                if (i <= k) time += tickets[k];
                else time += tickets[k] - 1;
            }
        }
        return time;
    }
};