class Solution {
    public String countOfAtoms(String formula) {
        int idx = formula.length() - 1;
        int[] muls = new int[idx + 1];
        int runMul = 1;

        Stack<Integer> st = new Stack<>();
        st.push(1);

        StringBuilder currNo = new StringBuilder();
        while (idx >= 0) {
            if (Character.isDigit(formula.charAt(idx))) currNo.insert(0, formula.charAt(idx));

            else if (Character.isAlphabetic(formula.charAt(idx))) currNo.setLength(0);

            else if (formula.charAt(idx) == '(') {
                runMul /= st.pop();
                currNo.setLength(0);
            }

            else if (formula.charAt(idx) == ')') {
                muls[idx] = currNo.length() > 0 ? Integer.parseInt(currNo.toString()) : 1;
                runMul *= muls[idx];
                st.push(muls[idx]);
                currNo.setLength(0);
            }

            muls[idx--] = runMul;
        }

        Map<String, Integer> finMap = new HashMap<>();
        StringBuilder currAtom = new StringBuilder();
        idx = 0;
        while (idx < formula.length()) {
            if (!Character.isUpperCase(formula.charAt(idx++))) continue;

            currAtom.setLength(0);
            currAtom.append(formula.charAt(idx - 1));
            currNo.setLength(0);
            while (idx < formula.length() && Character.isLowerCase(formula.charAt(idx))) currAtom.append(formula.charAt(idx++));

            while (idx < formula.length() && Character.isDigit(formula.charAt(idx))) currNo.append(formula.charAt(idx++));

            runMul = currNo.length() > 0 ? Integer.parseInt(currNo.toString()) : 1;

            finMap.put(currAtom.toString(), finMap.getOrDefault(currAtom.toString(), 0) + runMul * muls[idx - 1]);
        }

        TreeMap<String, Integer> sortedFin = new TreeMap<>(finMap);

        currAtom.setLength(0);
        for (String atom : sortedFin.keySet()) {
            currAtom.append(atom);
            if (sortedFin.get(atom) > 1) currAtom.append(sortedFin.get(atom));
        }

        return currAtom.toString();
    }
}