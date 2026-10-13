class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_most = vector<int>(height.size());
        vector<int> right_most = vector<int>(height.size());

        stack<int> st = {};
        for (int i = 0; i < height.size(); i++) {
            int val = height[i];

            while (!st.empty() && height[st.top()] <= val) {
                st.pop();
            }

            if (!st.empty()) {
                left_most[i] = st.top();
            } else {
                st.push(i);
                left_most[i] = i;
            }
        }

        while (!st.empty()) {
            st.pop();
        }

        for (int i = height.size() - 1; i >= 0; i--) {
            int val = height[i];
            while (!st.empty() && height[st.top()] <= val) {
                st.pop();
            }

            if (!st.empty()) {
                right_most[i] = st.top();
            } else {
                st.push(i);
                right_most[i] = i;
            }
        }

        int total = 0;
        for (int i = 0; i < height.size(); i++) {
            int val = height[i];
            int diff = min(height[left_most[i]], height[right_most[i]]) - val;

            total += diff;
        }

        return total;
    }
};
