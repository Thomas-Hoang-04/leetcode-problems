class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if m * n != len(original):
            return []

        return [[original[r * n + c] for c in range(n)] for r in range(m)]
        