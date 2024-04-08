class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count = 0;
        vector<int>::iterator s, i;
        while (count != students.size() && i != sandwiches.end()) {
            s = students.begin();
            i = sandwiches.begin();
            if (*s != *i) {
                students.push_back(*s);
                count++;
            } else {
                count = 0;
                sandwiches.erase(sandwiches.begin());
            }
            students.erase(students.begin());
        }
        return students.size();
    }
};