class Solution {
private:
    vector<int> par;
    int find(int node) {
        if (par[node] == -1) return node;

        return par[node] = find(par[node]);
    }
    int union_set(int node1, int node2) {
        int p1 = find(node1);
        int p2 = find(node2);

        if (p1 == p2) return 1;

        par[p2] = p1;
        return 0;
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int ptsPerE = grid.size() + 1;
        par = vector<int>(ptsPerE * ptsPerE, -1);

        int p;
        for (int r = 0; r < ptsPerE; r++) 
            for (int c = 0; c < ptsPerE; c++) {
                if (r == 0 || c == 0 || r == ptsPerE - 1 || c == ptsPerE - 1) {
                    p = r * ptsPerE + c;
                    par[p] = 0;
                }
            }
        
        par[0] = -1;

        int regCnt = 1;
        int top, bottom;

        for (int r = 0; r < grid.size(); r++) 
            for (int c = 0; c < grid.size(); c++) {
                if (grid[r][c] == '/') {
                    top = r * ptsPerE + c + 1;
                    bottom = (r + 1) * ptsPerE + c;
                    regCnt += union_set(top, bottom);
                } else if (grid[r][c] == '\\') {
                    top = r * ptsPerE + c;
                    bottom = (r + 1) * ptsPerE + c + 1;
                    regCnt += union_set(top, bottom);
                }
            }

        return regCnt;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();