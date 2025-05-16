class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    int len = heights.size();
    if (len == 0) return 0;

    vector<int> prev(len, -1), next(len, len);
    stack<int> s;

    // Fill the prev array
    for (int i = 0; i < len; ++i) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        if (!s.empty()) {
            prev[i] = s.top();
        }
        s.push(i);
    }

    while (!s.empty()) {
        s.pop();
    }

    // Fill the next array
    for (int i = len - 1; i >= 0; --i) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        if (!s.empty()) {
            next[i] = s.top();
        }
        s.push(i);
    }

    int max_area = 0;
    for (int i = 0; i < len; ++i) {
        max_area = max(max_area, heights[i] * (next[i] - prev[i] - 1));
    }

    return max_area;
}
};