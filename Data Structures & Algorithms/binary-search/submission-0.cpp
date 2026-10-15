class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }

    int search(vector<int>& nums, int left, int right, int target) {
        if (left > right) {
            return -1;
        }

        int mid = (left + right) / 2;
        int val = nums[mid];

        if (val == target) {
            return mid;
        } else if (val < target) {
            return search(nums, mid + 1, right, target);
        } else {
            return search(nums, left, mid - 1, target);
        }

    }
};
