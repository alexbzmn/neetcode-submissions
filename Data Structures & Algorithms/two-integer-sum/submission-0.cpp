class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        std::unordered_map<int, int> map = {};
    
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (map.contains(target - nums[i])) {
                int a = map[target - nums[i]];
                int b = i;

                if (a == b) {
                    continue;
                }

                return std::vector<int>{std::min(a, b), std::max(a, b)};
            }
        }
        
        return std::vector<int>{};
    }
};
