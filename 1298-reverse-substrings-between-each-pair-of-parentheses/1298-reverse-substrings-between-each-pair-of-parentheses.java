class Solution {
    public String reverseParentheses(String s) {
        Stack<Integer> match_par = new Stack<>();
        int[] match = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') match_par.push(i);
            else if (s.charAt(i) == ')') {
                match[i] = match_par.peek();
                match[match_par.pop()] = i;
            }
        }
        String res = "";
        for (int i = 0, dir = 1; i < s.length(); i += dir) {
            if (s.charAt(i) == '(' || s.charAt(i) == ')') {
                i = match[i];
                dir = -dir;
            } else res += s.charAt(i);
        }
        return res;
    }
}