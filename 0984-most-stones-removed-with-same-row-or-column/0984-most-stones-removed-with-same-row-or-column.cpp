#pragma GCC optimize(O3, "unroll-loops")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")

class Solution {
private: 
    class UnionFind {
    private: 
        vector<int> par;
        vector<bool> visited;
        int cnt;
        int find(int node) {
            if (!visited[node]) {
                cnt++;
                visited[node] = true;
            }
            if (par[node] == -1) return node;

            return par[node] = find(par[node]);
        }
    public:
        UnionFind(int size) {
            par = vector<int>(size, -1);
            visited = vector<bool>(size, false);
            cnt = 0;
        }

        int retCnt() { return cnt; }

        void unionNode(int n1, int n2) {
            n1 = find(n1);
            n2 = find(n2);

            if (n1 == n2) return;

            par[n1] = n2;
            cnt--;
        }
    };
public:
    int removeStones(vector<vector<int>>& stones) {
        if (stones.size() == 1) return 0;
    
        int rowMax = INT_MIN, colMax = INT_MIN;
        for (vector<int>& stone: stones) {
            rowMax = max(rowMax, stone[0]);
            colMax = max(colMax, stone[1]);
        }

        UnionFind uf(rowMax + colMax + 2);

        for (vector<int>& stone: stones) uf.unionNode(stone[0], stone[1] + rowMax + 1);
        
        return stones.size() - uf.retCnt();            
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();