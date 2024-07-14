class Solution {
public:
    string countOfAtoms(string formula) {
        int idx = formula.size() - 1;
        vector<int> muls(idx + 1);
        int runMul = 1;

        stack<int> st;
        st.push(1);

        string currNo = "";
        while (idx >= 0) {
            if (isdigit(formula[idx])) currNo = formula[idx] + currNo;

            else if (isalpha(formula[idx])) currNo = "";

            else if (formula[idx] == '(') {
                runMul /= st.top();
                st.pop();
                currNo = "";
            }

            else if (formula[idx] == ')') {
                muls[idx] = currNo.empty() ? 1 : stoi(currNo);
                runMul *= muls[idx];
                st.push(muls[idx]);
                currNo = "";
            }

            muls[idx--] = runMul;
        }

        unordered_map<string, int> finMap;
        string currAtom, currCnt;
        idx = 0;
        while (idx < formula.size()) {
            if (!isupper(formula[idx++])) continue; 
            
            currAtom = "";
            currAtom += formula[idx - 1];
            currCnt = "";
            while (idx < formula.size() && islower(formula[idx])) currAtom += formula[idx++];

            while (idx < formula.size() && isdigit(formula[idx])) currCnt += formula[idx++];

            runMul = currCnt.empty() ? 1 : stoi(currCnt);

            finMap[currAtom] += runMul * muls[idx - 1];
        }

        map<string, int> sortedFin(finMap.begin(), finMap.end());

        string ans = "";
        for (auto &[atom, cnt]: sortedFin) {
            ans += atom;
            if (cnt > 1) ans += to_string(cnt);
        }

        return ans;
    }
};