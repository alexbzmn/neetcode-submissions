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

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[left] > nums[mid] || nums[mid] > nums[right]) {
            if (nums[left] > nums[mid] && target < nums[mid]) {
                return search(nums, left, mid - 1, target);
            } else {
                return search(nums, mid + 1, right, target);
            }
        } else {
            if (nums[mid] < target) {
                return search(nums, mid + 1, right, target);
            } else {
                return search(nums, left, mid - 1, target);
            }
        }
    }
};
