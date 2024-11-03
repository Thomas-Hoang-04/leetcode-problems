class Solution {
    fun rotateString(s: String, goal: String): Boolean {
        if (s == goal) return true
        if (s.length != goal.length) return false
        return (s + s).contains(goal, true)
    }
}