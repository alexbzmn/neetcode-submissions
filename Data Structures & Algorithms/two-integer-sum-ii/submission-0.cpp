class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;


        vector<int> res(2);

        while (left < right) {

            int curr_sum = numbers[left] + numbers[right];
            if (curr_sum == target) {
                res[0] = left + 1;
                res[1] = right + 1;

                return res;
            } else if (curr_sum < target) {
                left++;
            } else if (curr_sum > target) {
                right--;
            }
        }

        return res;
    }
};
