class Solution {
public:
    int findMin(vector<int> &nums) {
        return find_min(nums, 0, nums.size() - 1);
    }

    int find_min(vector<int> &nums, int left, int right) {
        if (right - left == 1) {
            return min(nums[left], nums[right]);
        } else if (left == right) {
            return nums[left];
        }

        int mid = (left + right) / 2;

        if (nums[mid] > nums[right]) {
            return find_min(nums, mid, right);
        } else if (nums[mid] < nums[left]) {
            return find_min(nums, left, mid);
        } else {
            return find_min(nums, left, mid);
        }
    }
};
