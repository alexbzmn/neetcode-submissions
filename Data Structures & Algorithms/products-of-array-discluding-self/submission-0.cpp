class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        // [1, 2, 8, 48]
        vector<int> forward(nums.size());

        // [48, 48, 24, 6]
        vector<int> backward(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            forward[i] = i - 1 >= 0 ? forward[i - 1] * nums[i] : nums[i];
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            backward[i] = i + 1 < nums.size() ? backward[i + 1] * nums[i] : nums[i];
        }

        vector<int> res = {};

        for (int i = 0; i < nums.size(); i++) {
            int f = i - 1 >= 0 ? forward[i - 1] : 1;
            int b = i + 1 < backward.size() ? backward[i + 1] : 1;
            int p = f * b;

            res.push_back(p);
        }

        return res;
    }
};
