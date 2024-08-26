/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root) return {};

        vector<int> res;

        stack<Node*> trav;
        trav.push(root);

        Node* t;
        while (!trav.empty()) {
            t = trav.top();
            trav.pop();

            res.push_back(t->val);

            for (Node* c: t->children) trav.push(c);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();