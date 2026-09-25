class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {};

        for (int i = 0; i < nums.size(); i++) {

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = nums.size() - 1;
            int a = nums[i];

            while (left < right) {
                int b = nums[left];
                int c = nums[right];
                int sum = a + b + c;

                if (sum == 0) {
                    res.push_back(vector<int>{a, b, c});

                    while (left + 1 < nums.size() 
                    && nums[left] == nums[left + 1]) {
                        left++;
                    }
                }

                if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return res;
    }
};
