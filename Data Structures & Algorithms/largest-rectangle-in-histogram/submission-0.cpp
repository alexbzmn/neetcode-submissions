class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> left(heights.size(), -1);
        vector<int> right(heights.size(), n);

        stack<int> st = {};
        
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (!st.empty()) {
                left[i] = st.top();
            }

            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        for (int i = heights.size() - 1; i >= 0; i--) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if (!st.empty()) {
                right[i] = st.top();
            }

            st.push(i);
        }

        int max_area = 0;

        for (int i = 0; i < heights.size(); i++) {
            
            int left_bound = left[i] + 1;
            int right_bound = right[i] - 1;
            int val = heights[i];

            max_area = max(max_area, ((right_bound - left_bound) + 1) * val);
        }

        return max_area;
    }
};
