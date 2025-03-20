class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();
        int max_area = 0;
        
        vector<int> left(n), right(n);
        left[0] = -1;
        right[n - 1] = n;

        for (int i = 1; i < n; i++) {
            int k = i - 1;
            while (k >= 0 && heights[i] <= heights[k]) k = left[k];
            left[i] = k;
        }

        for (int i = n - 2; i >= 0; i--) {
            int k = i + 1;
            while (k < n && heights[i] <= heights[k]) k = right[k];
            right[i] = k;
        }

        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            max_area = max(max_area, heights[i] * width);
        }
        return max_area;
    }
};