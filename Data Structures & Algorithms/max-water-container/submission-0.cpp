class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;

        int res = 0;

        while (l < r) {
            int curr = (r - l) * min(heights[l], heights[r]);
            res = max(res, curr);

            if (heights[r] > heights[l]) {
                l++;
            } else if (heights[l] > heights[r]) {
                r--;
            } else {
                if (heights[r - 1] > heights[l + 1]) {
                    r--;
                } else {
                    l++;
                }
            }
        }

        return res;
    }
};
