/**
 * @param {number[]} original
 * @param {number} m
 * @param {number} n
 * @return {number[][]}
 */
var construct2DArray = function(original, m, n) {
    if (m * n != original.length) return [];

    return [...Array(m)].map((_, idx) => [...Array(n)].map((_, id) => original[idx * n + id]));
};