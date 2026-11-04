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

            int a = search(nums, left, mid - 1, target);
            int b = search(nums, mid + 1, right, target);
        
            return a != -1 ? a : b;
        } else {
            if (nums[mid] < target) {
                return search(nums, mid + 1, right, target);
            } else {
                return search(nums, left, mid - 1, target);
            }
        }
    }
};
