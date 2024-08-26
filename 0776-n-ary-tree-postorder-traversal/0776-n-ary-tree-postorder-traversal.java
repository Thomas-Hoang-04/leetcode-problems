/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<Integer> postorder(Node root) {
        if (root == null) return new ArrayList<Integer>();

        List<Integer> ans = new ArrayList<>();

        Stack<Node> trev = new Stack<>();
        Stack<Node> rev = new Stack<>();

        trev.push(root);
        Node t;

        while (!trev.isEmpty()) {
            t = trev.pop();
            rev.push(t);

            for (Node c: t.children) trev.push(c);
        }

        while (!rev.isEmpty()) ans.add(rev.pop().val);

        return ans;
    }
}